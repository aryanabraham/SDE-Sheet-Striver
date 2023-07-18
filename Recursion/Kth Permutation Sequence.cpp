#include <bits/stdc++.h>
using namespace std;

string kthPermutation(int n, int k) {
    // Write your code here.
    int fact = 1;
    string ans = "";
    vector<int> numbers;

    for(int i = 1; i < n; i++){
        fact *= i;
        numbers.push_back(i);
    }
    
    numbers.push_back(n);
    k--;

    while(1){
        int pos = k/fact;
        ans += to_string(numbers[pos]);
        numbers.erase(numbers.begin() + pos);

        if(numbers.size() == 0){
            break;
        }
        
        k %= fact;
        fact /= numbers.size();
    }
    return ans;
}
