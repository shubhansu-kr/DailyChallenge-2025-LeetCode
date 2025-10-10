// https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10

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
    int maximumEnergy(vector<int>& e, int k) {
        int n = e.size();
        int res = INT_MIN;
        vector<int> dp(n, INT_MIN);
        for (int i = 0; i < n; i++) {
            dp[i] = e[i];
            if (i - k >= 0)
                dp[i] = max(dp[i], e[i] + dp[i - k]);
            if (i + k >= n)
                res = max(res, dp[i]);
        }
        return res;
    }
};

int main () {
    
    return 0;
}