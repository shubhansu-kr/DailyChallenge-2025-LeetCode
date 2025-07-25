// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/?envType=daily-question&envId=2025-07-25

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
    int maxSum(vector<int>& nums) {
        int M = *max_element(nums.begin(), nums.end());
        if (M <= 0)
            return M;
            
        set<int> st;
        for (int i : nums)
            st.insert(i);

        int ans = 0;
        for (int it : st)
            if (it > 0)
                ans += it;

        return ans;
    }
};

int main () {
    
    return 0;
}