void generateSubsets(int idx, int target, vector<int> &arr, vector<int> &subset, vector<vector<int>> &uniqueSubsets){
	if(target == 0){
		uniqueSubsets.push_back(subset);
		return;
	}
	
	for(int i = idx; i < arr.size(); i++){
		if((i != idx) && (arr[i-1] == arr[i]){
			continue;
		}

		if(target < arr[i]){
			return;
		}
		
		subset.push_back(arr[i]);
		generateSubsets((i + 1), (target - arr[i]), arr, subset, uniqueSubsets);
		subset.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.

	vector<int> subset;
	vector<vector<int>> uniqueSubsets;

	sort(arr.begin(), arr.end());
	
	generateSubsets(0, target, arr, subset, uniqueSubsets);
	return uniqueSubsets;
}
