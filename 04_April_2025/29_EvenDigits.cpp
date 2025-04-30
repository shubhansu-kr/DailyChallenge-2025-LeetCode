// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/?envType=daily-question&envId=2025-04-30

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
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int digitCount = 0;
            while (nums[i] > 0)
            {
                digitCount++;
                nums[i] /= 10;
            }
            if (digitCount % 2 == 0)
            {
                evenCount++;
            }
        }
        return evenCount;
    }
};

int main () {
    
    return 0;
}