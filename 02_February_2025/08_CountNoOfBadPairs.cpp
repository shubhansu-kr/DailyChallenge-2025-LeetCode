// https://leetcode.com/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-02-09

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
    long long countBadPairs(vector<int>& nums) {
        long long total = (nums.size() * (nums.size() - 1)) / 2;
        unordered_map<int, int> freq;
        long long good = 0;

        for (int i = 0; i < nums.size(); i++) {
            good += freq[nums[i] - i];
            freq[nums[i] - i]++;
        }

        return total - good;
    }
};

int main () {
    
    return 0;
}
