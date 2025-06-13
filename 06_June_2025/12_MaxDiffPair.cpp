// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/?envType=daily-question&envId=2025-06-13

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
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];
        while (left < right)
        {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i)
            {
                if (nums[i] - nums[i - 1] <= mid)
                {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main () {
    
    return 0;
}