#include <bits/stdc++.h> 
bool sortByEndTime(vector<int>& a, vector<int>& b){
    if(a[2] == b[2]){
        return (a[0] < b[0]);
    }
    return (a[2] < b[2]);
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<int> meetingsOrganized;
    int numberOfMeetings = start.size();
    vector<vector<int>> meetingUtils;

    for(int i = 0; i < numberOfMeetings; i++){
        meetingUtils.push_back({(i + 1), start[i], end[i]});
    }

    sort(meetingUtils.begin(), meetingUtils.end(), sortByEndTime);
    
    meetingsOrganized.push_back(meetingUtils[0][0]);
    int lastMeetingEndTime = meetingUtils[0][2];
    
    for(int i = 0; i < numberOfMeetings; i++){
        if(meetingUtils[i][1] > lastMeetingEndTime){
            meetingsOrganized.push_back(meetingUtils[i][0]);
            lastMeetingEndTime = meetingUtils[i][2];
        }
    }
    return meetingsOrganized;   
}
