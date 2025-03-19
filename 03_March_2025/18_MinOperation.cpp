// https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/?envType=daily-question&envId=2025-03-19

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
    void flip(int start, int end, vector<int>& nums) {
        for(int i=start; i<=end;i++) {
            nums[i] = !nums[i];
        }
    }
    bool check(vector<int>& nums, int i, int n) {
        for(int j = i;j<n;j++)
            if(!nums[j])
                return false;
        return true;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if( n < 3)
            return -1;

        int count = 0;
        for(int i=0; i<=n-3; i++) {
            if(!nums[i]) {
                flip(i, i+2, nums);
                count++;
            }
            if(check(nums, i, n))
                return count;
        }
        return -1;
    }
};

int main () {
    
    return 0;
}
