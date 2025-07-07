//  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/?envType=daily-question&envId=2025-07-07

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
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, index = 0, n = events.size(), result = 0;
        
        while (!minHeap.empty() || index < n) {
            if (minHeap.empty()) {
                day = events[index][0];
            }
            while (index < n && events[index][0] <= day) {
                minHeap.push(events[index][1]);
                index++;
            }
            minHeap.pop();
            result++;
            day++;
            
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}