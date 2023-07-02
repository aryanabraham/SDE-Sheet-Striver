#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longConsSeq = 0;
    unordered_set<int> us;

    for(int i = 0; i < n; i++){
        us.insert(arr[i]);
    }

    for(int i = 0; i < n; i++){
        auto it = us.find(arr[i] - 1);

        if(it == us.end()){
            int consSeq = 0;
            it = us.find(arr[i] + consSeq);

            while(it != us.end()){
                consSeq++;
                it = us.find(arr[i] + consSeq);
            }
            longConsSeq = max(longConsSeq, consSeq);
        }
    }
    return longConsSeq;
}
