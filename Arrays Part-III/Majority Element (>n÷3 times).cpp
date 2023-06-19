#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int i = 0;
    int n = arr.size();
    int ctr1 = 0;
    int ctr2 = 0;
    int majEle1 = -1;
    int majEle2 = -1;
    vector<int> majorityElements;

    while(i < n){
        if(arr[i] == majEle1){
            ctr1++;
        }
        else if(arr[i] == majEle2){
            ctr2++;
        }
        else if(ctr1 == 0){
            ctr1 = 1;
            majEle1 = arr[i];
        }
        else if(ctr2 == 0){
            ctr2 = 1;
            majEle2 = arr[i];
        }
        else{
            ctr1--;
            ctr2--;
        }
        i++;
    }

    i = 0;
    ctr1 = 0;
    ctr2 = 0;

    while(i < n){
        if(arr[i] == majEle1){
            ctr1++;
        }
        else if(arr[i] == majEle2){
            ctr2++;
        }
        i++;
    }

    if(ctr1 > (n / 3)){
        majorityElements.push_back(majEle1);
    }
    if(ctr2 > (n / 3)){
        majorityElements.push_back(majEle2);
    }
    return majorityElements;    
}
