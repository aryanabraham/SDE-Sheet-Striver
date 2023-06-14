#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int i = 1;
	int ctr = 1;
	int freq = 0;
	int majEle = arr[0];

	while(i < n){
		if(arr[i] == majEle)
			ctr++;
		else
			ctr--;

		if(ctr == 0){
			ctr = 1;
			majEle = arr[i];
		}
		i++;
	}

	i = 0;

	while(i < n){
		if(arr[i] == majEle){
			freq++;
		}
		i++;
	}

	return (freq > (n / 2)) ? majEle : -1;
}
