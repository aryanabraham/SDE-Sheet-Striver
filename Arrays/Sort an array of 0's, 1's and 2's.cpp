#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int low = 0, high = (n - 1);
   int i = low;

   while(i <= high){
      if(arr[i] == 0){
         swap(arr[low], arr[i]);
         low++, i++;
      }

      else if(arr[i] == 1)
         i++;

      else{
        swap(arr[i], arr[high]);
        high--;
      }
   }
}
