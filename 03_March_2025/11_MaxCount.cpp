// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/?envType=daily-question&envId=2025-03-12

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
    int maximumCount(vector<int>& nums) {
        int t = nums.size() - (lower_bound(nums.begin(), nums.end(), 1) - nums.begin());
        int p = (lower_bound(nums.begin(), nums.end(), 0) - nums.begin());

        return max(t, p);
    }
};

int main () {
    
    return 0;
}
