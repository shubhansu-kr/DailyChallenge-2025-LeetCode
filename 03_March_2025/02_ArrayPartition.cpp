// https://leetcode.com/problems/partition-array-according-to-given-pivot/?envType=daily-question&envId=2025-03-03

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
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
            {
                v.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == pivot)
            {
                v.push_back(nums[i]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > pivot)
            {
                v.push_back(nums[i]);
            }
        }
        return v;
    }
};

int main () {
    
    return 0;
}
