// https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20

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
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for (auto& q : queries) {
            diff[q[0]]--;
            if (q[1] + 1 < n) diff[q[1] + 1]++;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (nums[i] > -sum) return false;
        }return true;
    }
};

int main () {
    
    return 0;
}