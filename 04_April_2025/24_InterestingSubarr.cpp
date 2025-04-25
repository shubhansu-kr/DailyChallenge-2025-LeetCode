// https://leetcode.com/problems/count-of-interesting-subarrays/?envType=daily-question&envId=2025-04-25

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
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] % m == k){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        unordered_map<int,long long> mp;
        long long sum =0;
        long long result = 0;
        mp[0]=1;
        for(int i=0; i<n ; i++){
            sum += nums[i];
            int r1 = sum%m;
            int r2=(r1-k+m)%m;
            result += mp[r2];
            mp[r1]++;
        }
        return result;
    }
};

int main () {
    
    return 0;
}