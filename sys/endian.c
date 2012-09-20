#include <stdio.h>
#include <arpa/inet.h>

static void print_bytes(void *ptr, int size)
{
  char *c = ptr;
  int i;
  for (i = 0; i < size; i++)
    printf("0x%04x: %02x\n", i * 8, (unsigned int)*(c++));
}

int main(int argc, char *argv[])
{
  uint32_t n = 1;
  uint32_t bn;
  char *char_list = "12345";
  long long int nn = 1;

  printf("ascii\n");
  printf("'1' : 0x%x\n", '1');
  printf("'2' : 0x%x\n", '2');
  printf("'a' : 0x%x\n", 'a');
  printf("'b' : 0x%x\n", 'b');
  printf("'A' : 0x%x\n", 'A');
  printf("'B' : 0x%x\n", 'B');
  
  printf("\nuint32_t 1\n");
  print_bytes(&n, sizeof(n));

  bn = htonl(n);
  printf("\nBigEndian uint32_t 1\n");
  print_bytes(&bn, sizeof(bn));
  
  printf("\n\"12345\"\n");
  print_bytes(char_list, sizeof(char_list));

  nn = 1;
  nn = nn << 32;
  nn |= 2;			/* nn == 00 00 00 01 00 00 00 02 */
  printf("\n\"long long int 1\"\n");
  print_bytes(&nn, sizeof(nn));
  
  return 0;
}
