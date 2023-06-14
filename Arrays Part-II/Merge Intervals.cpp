#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool sortByStart(vector<int>& a, vector<int>& b){
    return (a[0] < b[0]);
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    int i = 0;
    vector<vector<int>> mergedIntervals;
    int numberOfIntervals = intervals.size();

    sort(intervals.begin(), intervals.end(), sortByStart);

    while(i < numberOfIntervals){
        int j = (i + 1);
        int startTime = intervals[i][0];
        int endTime = intervals[i][1];

        while((j < numberOfIntervals) && (endTime >= intervals[j][0])){
            endTime = max(endTime, intervals[j][1]);
            j++;
        }

        mergedIntervals.push_back({startTime, endTime});
        i = j;
    }
    return mergedIntervals;
}
