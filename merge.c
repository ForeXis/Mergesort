#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>


#define RMAX 100

typedef uint64_t data;

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

free(arr); 
return 0;
}

void array_print(const data *a, uint64_t n) {
  for(uint64_t i = 0; i < n; ++i)
    printf("%u\t", a[i]);
  printf("\n");
}
