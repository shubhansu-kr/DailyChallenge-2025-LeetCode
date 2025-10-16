// https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/?envType=daily-question&envId=2025-10-16

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
    int findSmallestInteger(vector<int>& nums, int value) {
        vector <int> mods(value, false);
        for (int i = 0; i < nums.size(); i++)
        {
            int data = ((nums[i] % value) + value) % value;
            mods[data]++;
        }
        int mn = INT_MAX;
        int mi = -1;
        for (int i = 0; i < value; i++)
        {
            if (mods[i] < mn)
            {
                mn = mods[i];
                mi = i;
            }
        }
        int ans = mi + (mods[mi]) * value;
        
        return ans;
    }
};

int main () {
    
    return 0;
}