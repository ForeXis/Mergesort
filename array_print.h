#ifndef ARRAY_PRINT_H
#define ARRAY_PRINT_H

#include <stdio.h>


typedef uint64_t data;

  
  
void array_print(const data *a, uint64_t n) {
  for(uint64_t i = 0; i < n; ++i)
    printf("%u\t", a[i]);
  printf("\n");
  printf("\n");
}


#endif
