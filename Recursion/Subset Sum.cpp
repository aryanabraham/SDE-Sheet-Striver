#include <bits/stdc++.h>
void generateSubsets(int idx, int sum, vector<int>& nums, vector<int>& subsetSums){
    if(idx == nums.size()){
        subsetSums.push_back(sum);
        return;
    }

    generateSubsets((idx + 1), (sum + nums[idx]), nums, subsetSums);
    generateSubsets((idx + 1), sum, nums, subsetSums);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> subsetSums;

    generateSubsets(0, 0, num, subsetSums);

    sort(subsetSums.begin(), subsetSums.end());
    return subsetSums;
}
