// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2025-01-25

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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> order(n), newOrder, ans(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int &i, int &j) {
            return nums[i] < nums[j];
        });
        newOrder.assign(order.begin(), order.end());
        int start = 0;
        for(int i = 1; i < n; i++) {
            if(nums[order[i]] - nums[order[i - 1]] > limit) {
                sort(newOrder.begin() + start, newOrder.begin() + i);
                start = i;
            }
        }
        sort(newOrder.begin() + start, newOrder.end());
        for(int i = 0; i < n; i++) {
            ans[newOrder[i]] = nums[order[i]];
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
