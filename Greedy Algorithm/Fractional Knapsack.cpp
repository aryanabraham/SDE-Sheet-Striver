#include <bits/stdc++.h> 
bool sortByValPerWt(pair<int, int>& a, pair<int, int>& b){
    double valPerWtA = ((a.second) / (1.0 * a.first));
    double valPerWtB = ((b.second) / (1.0 * b.first));

    return valPerWtA > valPerWtB;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    double maxVal = 0;

    sort(items.begin(), items.end(), sortByValPerWt);

    for(int i = 0 ; i < n; i++){
        if(items[i].first < w){
            w -= items[i].first;
            maxVal += items[i].second;
        }
        
        else{
            double unitVal = ((items[i].second) / (1.0 * items[i].first));
            maxVal += (unitVal * w);
            break;
        }
    }
    return maxVal;
}
