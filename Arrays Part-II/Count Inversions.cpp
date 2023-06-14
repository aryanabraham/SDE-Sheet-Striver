#include <bits/stdc++.h> 

long long merge(long long l, long long mid, long long r, long long *arr){
    long long i, j, k;
    long long inversions = 0;
    long long n1 = (mid - l + 1), n2 = (r - mid);
    vector<long long> a, b;

    for(i = 0; i < n1; i++){
        a.push_back(arr[l+i]);
    }

    for(j = 0; j < n2; j++){
        b.push_back(arr[mid+j+1]);
    }

    i = j = 0;
    k = l;
    
    while((i < n1) && (j < n2)){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }

        else{
            inversions += (n1 - i);
            arr[k++] = b[j++];
        }
    }

    while(i<n1){
        arr[k++] = a[i++];
    }

    while(j<n2){
        arr[k++] = b[j++];
    }
    return inversions;
}

long long mergeSort(long long l, long long r, long long *arr){
    long long inversions = 0;

    if(l < r){
        long long mid = (l + ((r - l) / 2));

        inversions += mergeSort(l, mid, arr);
        inversions += mergeSort((mid + 1), r, arr);
        inversions += merge(l, mid, r, arr);
    }
    return inversions;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(0, (n - 1), arr);
}
