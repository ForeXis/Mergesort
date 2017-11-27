#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include "array_print.h"


//#define NDEBUG

#ifndef NDEBUG
  #define DBGPRINT(...) printf(__VA_ARGS__)
  #define DBG(...) (__VA_ARGS__)
#else
  #define DBGPRINT(...) do{}while(0)
  #define DBG(...) do{}while(0)
#endif

#define RMAX 100



data *arr;
uint64_t len;


int main(void) {
  printf("Array length: ");
  scanf("%lu", &len);
  if(len < 2) {
    printf("Length >= 2\n");
    return 1;
  }

  srand(time(NULL));
  arr = malloc(len * sizeof(data));
  for(uint64_t i = 0; i < len; ++i)
    arr[i] = rand() / (RAND_MAX / (RMAX - 1));

  array_print(arr, len);
  merge_sort(arr, len);
  array_print(arr, len);

  free(arr);
  return 0;
}

data* merge(const data *a, uint64_t a_n,
            const data *b, uint64_t b_n) {
  data *res = malloc((a_n + b_n) * sizeof(data));
  uint64_t i = 0, j = 0;

  DBGPRINT("Merging blocks:\n");
  DBG(array_print(a, a_n));
  DBGPRINT("and\n");
  DBG(array_print(b, b_n));
  while((i < a_n) && (j < b_n))
    if(a[i] <= b[j]) {
      res[i + j] = a[i];
      ++i;
    } else {
      res[i + j] = b[j];
      ++j;
    }
  for(; i < a_n; ++i)
    res[i + j] = a[i];
  for(; j < b_n; ++j)
    res[i + j] = b[j];

  DBGPRINT("Result: ");
  DBG(array_print(res, a_n + b_n));
  return res;
}

void merge_sort(data *a, uint64_t n) {
  if(n < 2)
    return;

  for(uint64_t b = 1; b < n; b <<= 1) {
    DBGPRINT("block size = %lu\n", b);
    for(uint64_t i = 0, r = 0 ; i < n; i += 2 * b) {
      if(i + b >= n) {
        DBGPRINT("no pair for current block\n");
        break;
      }
      if(i + 2 * b > n)
        r = i + 2 * b - n;
      DBGPRINT("remainder = %lu\n", r);
      data *tmp = merge(a + i, b, a + i + b, b - r);
      memmove(a + i, tmp, (2 * b - r) * sizeof(data));
      free(tmp);
    }
  }
}

