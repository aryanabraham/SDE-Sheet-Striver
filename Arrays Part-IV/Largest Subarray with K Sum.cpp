#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
  int maxLen = 0;
  int preSum = 0;
  unordered_map<int, int> preSumIdx;

  preSumIdx.insert({0, -1});

  for(int i = 0; i < arr.size(); i++){
    preSum += arr[i];

    auto it = preSumIdx.find(preSum);
    if(it != preSumIdx.end()){
      int len = i - it->second;

      maxLen = max(maxLen, len);
    }
    
    else{
      preSumIdx[preSum] = i;
    }
  }
  return maxLen;
}
