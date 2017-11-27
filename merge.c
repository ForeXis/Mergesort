#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>


typedef uint64_t data;

uint64_t len;

int main(void) {
  printf("Array length: ");
  scanf("%lu", &len);
    if(len < 2) {
    printf("Length >= 2\n");
    return 1;
  }

  return 0;
}
