#include <bits/stdc++.h>

bool sortByEndTime(pair<int, int>& a, pair<int, int>& b){
    return (a.second < b.second);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int activitiesPerformed = 1;
    int numberOfActivities = start.size();
    vector<pair<int, int>> activityUtils;
    
    for(int i = 0 ; i < numberOfActivities; i++){
        activityUtils.push_back({start[i], finish[i]});
    }

    sort(activityUtils.begin(), activityUtils.end(), sortByEndTime);

    int lastActivityEndTime = activityUtils[0].second;

    for(int i = 1; i < numberOfActivities; i++){
        if(activityUtils[i].first >= lastActivityEndTime){
            activitiesPerformed++;
            lastActivityEndTime = activityUtils[i].second;
        }
    }
    return activitiesPerformed;
}
