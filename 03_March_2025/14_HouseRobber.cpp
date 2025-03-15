// https://leetcode.com/problems/house-robber-iv/?envType=daily-question&envId=2025-03-15

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
    bool canRobe(int mid, vector<int>& nums, int k) {

        int cntless = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] <= mid) {
                cntless++;
                i++;
            }
        }
        return cntless >= k;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end()), ans = r;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canRobe(mid, nums, k)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
