// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/?envType=daily-question&envId=2025-07-17

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return n;

        int ans = 0;

        for (int rem = 0; rem < k; ++rem) {
            vi dp(k, 0);

            for (int i = 0; i < n; ++i) {
                int mod = nums[i] % k;
                int req = (rem - mod + k) % k;
                dp[mod] = dp[req] + 1;
            }

            for (int x : dp) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};

int main () {
    
    return 0;
}