#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coinsTaken;
    int numberOfCoins = 0;
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    for(int i = (denominations.size() - 1); i > -1; i--){
        coinsTaken = (amount / denominations[i]);
        
        if(coinsTaken){
            numberOfCoins += coinsTaken;
            amount -= (coinsTaken * denominations[i]);
        }
    }
    return numberOfCoins;
}
