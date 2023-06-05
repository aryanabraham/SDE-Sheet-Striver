#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int breakPoint = -1;
    int nextGreatestInt = -1;

    for(int i = (n - 2); i > -1; i--){
        if(permutation[i] < permutation[i+1]){
            breakPoint = i;
            break;
        }
    }

    if(breakPoint == -1){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }

    for(int i = (n - 1); i > breakPoint; i--){
        if(permutation[breakPoint] < permutation[i]){
            nextGreatestInt = i;
            break;
        }
    }

    swap(permutation[breakPoint], permutation[nextGreatestInt]);
    reverse((permutation.begin() + breakPoint + 1), permutation.end());

    return permutation;
}
