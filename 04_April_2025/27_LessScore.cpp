// https://leetcode.com/problems/count-subarrays-with-score-less-than-k/?envType=daily-question&envId=2025-04-28

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
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        int start=0,end=0;
        int sizeOfArray = nums.size();
        long long sum = 0;
        while(start <= sizeOfArray && end <= sizeOfArray){

            if(sum*(end-start) < k){
                if(end > start && sum*(end-start) < k){
                    count+=end-start;
                }
                if(end < sizeOfArray) sum+=nums[end]; 
                end++;
            } else {
                sum -= nums[start];
                start++;
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}