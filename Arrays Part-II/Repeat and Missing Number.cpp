#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	int r, m;
	int sum;
	int difference;
	int differenceOfSquares;
	long long actualSum = 0;
	long long idealSum = ((n * (n + 1)) / 2);
	long long actualSumOfSquares = 0;
	long long idealSumOfSquares = ((n * (n + 1) * ((2 * n) + 1)) / 6);

	for(int i = 0 ; i < n; i++){
		actualSum += arr[i];
		actualSumOfSquares += pow(arr[i], 2);
	}

	difference = (actualSum - idealSum);
	differenceOfSquares = (actualSumOfSquares - idealSumOfSquares);

	sum = (differenceOfSquares / difference);
	r = (sum + difference) / 2;
	m = (sum - r);

	return {m, r};
}
