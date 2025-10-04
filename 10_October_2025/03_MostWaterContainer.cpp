// https://leetcode.com/problems/container-with-most-water/?envType=daily-question&envId=2025-10-04

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
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxi = 0;
        while (left < right)
        {
            int w = right - left;
            int h = min(height[left], height[right]);
            int area = h * w;
            maxi = max(maxi, area);
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else
            {
                left++;
                right--;
            }
        }
        return maxi;
    }
};

int main () {
    
    return 0;
}