// https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2025-09-22

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
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &it: nums) {
            mp[it]++;
        }
        int maxFreq = INT_MIN, count = 0;
        for(auto &it: mp){
            if (it.second > maxFreq){
                count = 1;
                maxFreq = it.second;
            }
            else if (it.second == maxFreq) ++count;
        }
        return count * maxFreq;
    }
};

int main () {
    
    return 0;
}