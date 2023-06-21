#include <bits/stdc++.h> 
void generateSubsets(int idx, vector<int> &arr, vector<int> &temp, vector<vector<int>> &unqSub){
    unqSub.push_back(temp);
    
    for(int i = idx; i < arr.size(); i++){
        if((idx != i) && (arr[i-1] == arr[i])){
            continue;
        }
        
        temp.push_back(arr[i]);
        generateSubsets((i + 1), arr, temp, unqSub);
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<int> temp;
    vector<vector<int>> unqSub;
    
    sort(arr.begin(), arr.end());
    generateSubsets(0, arr, temp, unqSub);
    return unqSub;
}
