// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/?envType=daily-question&envId=2025-06-29

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
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r)
        {
            if (nums[l] + nums[r] > target) {r--;}
            else{res = (res + pows[r - l++]) % mod;}
        }
        return res;
    }
};

int main () {
    
    return 0;
}