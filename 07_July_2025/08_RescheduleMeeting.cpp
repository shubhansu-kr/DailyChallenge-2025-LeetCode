// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/?envType=daily-question&envId=2025-07-09

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeGaps;

        for (int i = 0; i < startTime.size(); i++) {
            if (i == 0) {
                freeGaps.push_back(startTime[i]); 
            } else {
                freeGaps.push_back(startTime[i] - endTime[i - 1]); 
            }
            if (i == startTime.size() - 1) {
                freeGaps.push_back(eventTime - endTime[i]);
            }
        }

        int maxWindow = k + 1;
        int n = freeGaps.size();
        int maxFree = 0, currentSum = 0;
        int i = 0, j = 0;

        while (j < n) {
            currentSum += freeGaps[j];
            if (j - i + 1 == maxWindow) {
                maxFree = max(maxFree, currentSum);
                currentSum -= freeGaps[i];
                i++;
            }
            j++;
        }
        return maxFree;
    }
};

int main () {
    
    return 0;
}