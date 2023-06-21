#include <bits/stdc++.h>
int merge(int l, int mid, int r, vector<int> &arr){
	int i, j, k, revPair = 0; 
	int n1 = (mid - l + 1), n2 = (r - mid);
	vector<int> a, b;

	for(i = 0; i < n1; i++){
		a.push_back(arr[l+i]);
	}

	for(j = 0; j < n2; j++){
		b.push_back(arr[mid+j+1]);
	}

	for(i = 0, j = 0; i < n1; i++){
		while((j < n2) && (a[i] > (2 * b[j]))){
			j++;
		}
		revPair += j;
	}

	i=j=0;
	k=l;
	
	while((i < n1) && (j < n2)){
		if(a[i] < b[j]){
			arr[k] = a[i];
			i++;
			k++;
		} 
		
		else{
			arr[k] = b[j];
			j++;
			k++;
		}
	}

	while(i < n1){
		arr[k] = a[i];
		i++;
		k++;
	}

	while(j < n2){
		arr[k] = b[j];
		j++;
		k++;
	}
	return revPair;
}

int mergeSort(int l, int r, vector<int> &arr){
	int revPair = 0;

	if(l < r){
		int mid = l + (r - l)/2;

		revPair += mergeSort(l, mid, arr);
		revPair += mergeSort((mid + 1), r, arr);
		revPair += merge(l, mid, r, arr);
	}
	return revPair;
}

int reversePairs(vector<int> &arr, int n){
	// Write your code here.
	return mergeSort(0, (n - 1), arr);
}
