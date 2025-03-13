// https://leetcode.com/problems/zero-array-transformation-ii/?envType=daily-question&envId=2025-03-13

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
    bool check(int k, vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1);
        for(int i = 0; i < k; i++) {
            diff[queries[i][0]] -= queries[i][2];
            diff[queries[i][1]+1] += queries[i][2];
        }

        int d = 0;
        for(int i = 0; i < n; i++) {
            d += diff[i];
            int x = nums[i] + d;
            if(x > 0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l = 0;
        int r = queries.size();

        int ans = -1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(check(mid, nums, queries)) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
