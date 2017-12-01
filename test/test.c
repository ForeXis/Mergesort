#include "merge.h"

#include <stdio.h>
#include "ctest.h"

#define RMAX 100

typedef uint64_t data;

data *arr;


CTEST(suite1, test1){

  // Given
   uint64_t arr[20] = {0, 0, 3, 7, 9, 18, 23, 25, 27, 27, 32, 36, 45, 49, 63, 65, 81, 86, 94, 99};
  const uint64_t len = 20;
  
 
 merge_sort(arr, len);

  // Then
  const uint64_t /*expected*/ b[20] = {0, 0, 3, 7, 9, 18, 23, 25, 27, 27, 32, 36, 45, 49, 63, 65, 81, 86, 94, 99};




  
  for(uint64_t i = 0; i < len; ++i){
  	printf("compare %d %d =? %d\n", i , b[i], arr[i]);
  ASSERT_EQUAL(arr[i], b[i]);
  

  }
  
}

CTEST(suite2, test2){
int m, n;

uint64_t arr[20] = {0, 0, 3, 7, 9, 18, 23, 25, 27, 27, 32, 36, 45, 49, 63, 65, 81, 86, 94, 99};
  const uint64_t len = 20;

 merge_sort(arr, len);

  // Then
  for(int i = 0, j = 0; i < len; ++i){
  	if (arr[i] <= arr[i+1]){
  		j++ ;
		m = i+1;
		n = j;
	  }
}

  	printf("compare %d =? %d\n", n , m);
  ASSERT_EQUAL(n, m);
}
  












