#ifndef MERGE_H
#define MERGE_H


#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

typedef uint64_t data;

data* merge(const data *a, uint64_t a_n,
            const data *b, uint64_t b_n) {
  data *res = malloc((a_n + b_n) * sizeof(data));
  uint64_t i = 0, j = 0;

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

  return res;
}

void merge_sort(data *a, uint64_t n) {
  if(n < 2)
    return;

  for(uint64_t b = 1; b < n; b <<= 1) {
    for(uint64_t i = 0, r = 0 ; i < n; i += 2 * b) {
      if(i + b >= n) {
        break;
      }
      if(i + 2 * b > n)
        r = i + 2 * b - n;
      data *tmp = merge(a + i, b, a + i + b, b - r);
      memmove(a + i, tmp, (2 * b - r) * sizeof(data));
      free(tmp);
    }
  }
}

#endif
