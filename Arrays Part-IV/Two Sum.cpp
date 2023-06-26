#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   int numberOfElements = arr.size();
   vector<vector<int>> requiredPairs;
   
   sort(arr.begin(), arr.end());
   
   for(int i = 0; i < (numberOfElements - 1); i++){
      for(int j = (i + 1); j < numberOfElements; j++){
         if((arr[i] + arr[j]) == s){
            requiredPairs.push_back({arr[i], arr[j]});
         }
      }
   }
   return requiredPairs;
}
