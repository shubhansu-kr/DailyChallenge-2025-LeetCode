// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/?envType=daily-question&envId=2025-07-27

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
    int countHillValley(vector<int>& nums) {
        const int n=nums.size();
        int prev=nums[0], cnt=0;
        bool diff[2]={0, 0};
        for(int i=1; i<n; i++){
            while(i<n && prev==nums[i]) i++;
            if (i==n) break;
            bool bigger=nums[i]>prev;
            diff[bigger]=1;
            cnt+=diff[bigger] && diff[!bigger];
            diff[!bigger]=0;
            prev=nums[i];
        }
        return cnt;
    }
};

int main () {
    
    return 0;
}