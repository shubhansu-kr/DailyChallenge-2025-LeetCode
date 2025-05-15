// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=daily-question&envId=2025-05-15

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
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        ans.push_back(words[0]);
        int n = words.size();
        for(int i = 1; i < n; i++) {
            if(groups[i] != groups[i - 1]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}