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
  ASSERT_EQUAL(b[i], arr[i]);
  

  }
  
}
  












/*0       0       3       7       9       18      23      25      27      27      32      36      45      49      63
65      81      86      94      99*/

//void assert_data(const data *b, uint64_t m, /*exp, size_t expsize*/
//                const data *a, uint64_t n,/*real, size_t realsize*/
//                const char* caller, int line); /*char* caller, int line*/
