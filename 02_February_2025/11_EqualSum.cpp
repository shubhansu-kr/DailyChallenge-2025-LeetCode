// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/?envType=daily-question&envId=2025-02-12

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    int findSum(int num){
        int sum=0;
        while(num!=0){
            int digit= num%10;
            sum = sum + digit;
            num = num/10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = -1;
        for(int i=0;i<n;i++){
            int val = nums[i];
            int sum = findSum(val);
            if(mp.find(sum)!=mp.end()){
                ans = max(ans, val+mp[sum]);
                if(val>mp[sum]){
                    mp[sum]= val;
                }
            }
            else{
                mp[sum]=val;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
