void generateSubsets(int idx, int k, vector<int> &arr, vector<int> &temp, vector<vector<int>> &sol){
    if(idx == arr.size()){
        if(k == 0){
            sol.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[idx]);
    generateSubsets((idx + 1), (k - arr[idx]), arr, temp, sol);
    
    temp.pop_back();
    generateSubsets((idx + 1), k, arr, temp, sol);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<int> temp;
    vector<vector<int>> sol;

    generateSubsets(0, k, arr, temp, sol);
    return sol;
}
