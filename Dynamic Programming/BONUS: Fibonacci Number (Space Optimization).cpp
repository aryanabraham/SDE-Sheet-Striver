#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int prev1 = 1;
    int prev2 = 0;
    
    cin>>n;
    for(int i = 2; i <= n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1;
    return 0;
}
