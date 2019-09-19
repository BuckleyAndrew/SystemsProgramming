// indentation = 2 spaces
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  unsigned long int i;
  // checking there is a command line aargument
  if (argc != 2) {
    printf("Usage: %s number\n", argv[0]);
    return 0;
  }
  // converting the command line argument to a unsigned long
  // and exit program if there is an error during the conversion.
  errno = 0;
  i = strtoul(argv[1], NULL, 0);
  if (errno != 0) {
    perror("Failed to convert number");
    return 0;
  }
  // return 0 if 0x0 is entered
  if (i == 0) {
    printf("%lu\n", i);
    return 0;
  }
  // create a 64 element array where the bits wil be stored and a count value
  int binary[64], bitCount = 0; 
  // perform a (mod 2) operation on entered value and store the remainder
  // subtract the remainder (to prevent fractions) from the value and divide 2
  while (i > 1) {
    binary[bitCount++] = i % 2;
    i = (i - ( i % 2)) / 2;
  }
  binary[bitCount] = 1;
  // print each element of the array in reverse of how it is stored
  // element [0] is the least significant bit
  while (bitCount >= 0) {
    printf("%d", binary[bitCount--]);
  }
  printf("\n");
  return 0;
}
