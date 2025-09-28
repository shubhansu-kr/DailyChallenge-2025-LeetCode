// https://leetcode.com/problems/largest-perimeter-triangle/?envType=daily-question&envId=2025-09-28

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
    int largestPerimeter(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i > 1; --i)
        {
            int x = nums[i];
            if (x < nums[i-1]+nums[i-2]) {
                sum = nums[i] + nums[i-1] + nums[i-2];
                break;
            }
        }
        return sum;
    }
};

int main () {
    
    return 0;
}