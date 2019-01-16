// A recursive solution for subset sum problem 
#include <stdio.h> 
#include<stdbool.h>
  
// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int set[], int size, int sum) 
{ 
   // Base Cases 
   if (sum == 0) 
     return true; 
   if size == 0 && sum != 0) 
     return false; 
  
   // If last element is greater than sum, then ignore it 
   if (set[size-1] > sum) 
     return isSubsetSum(set, size-1, sum); 
  
   /* else, check if sum can be obtained by any of the following 
      (a) including the last element 
      (b) excluding the last element   */
   return isSubsetSum(set, size-1, sum) ||  
                        isSubsetSum(set, size-1, sum-set[size-1]); 
} 
  
// Driver program to test above function 
int main() 
{ 
  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int num = sizeof(set)/sizeof(set[0]); 
  if (isSubsetSum(set, size, sum))  
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
} 
