#include <bits/stdc++.h> 
bool sortByProfit(vector<int>& a, vector<int>& b){
    return (a[1] > b[1]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int maxTime = 1;
    int totalProfit = 0;
    int numberOfJobs = jobs.size();

    sort(jobs.begin(), jobs.end(), sortByProfit);
    
    for(int i = 0; i < numberOfJobs; i++){
        maxTime = max(maxTime, jobs[i][0]);
    }

    vector<bool> jobSchedule(maxTime, false);
    
    for(int i = 0; i < numberOfJobs; i++){
        for(int j = (jobs[i][0] - 1); j > -1; j--){
            if(!jobSchedule[j]){
                jobSchedule[j] = true;
                totalProfit += jobs[i][1];
                break;
            }
        }
    }
    return totalProfit;
}
