#include <stdio.h>
int main(void) {
  int count = 0;
  int i = 100; // -> 01100100

  while (count < 8) {
    printf("%d", i & 1);
    i = (i >> 1);
    count++;
  }
  //   i = i >> 1; // -> 00110010
  //   printf("Result is: %d\n", i & 1);
  //   i = i >> 1; // -> 00011001
  //   printf("Result is: %d\n", i & 1);
  //   i = i >> 1; // -> 00001100
  //   printf("Result is: %d\n", i & 1);
  return 0;
}

// 01100100 -> 0
// 00110010 -> 0
// 00011001 -> 1
// 00001100 -> 0
// 00000110 -> 0
// 00000011 -> 1
// 00000001 -> 1
// 00000000 -> 0