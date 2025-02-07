// https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06

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
        int tupleSameProduct(vector<int>& nums) {
            unordered_map<int , int> mp;
            int n = nums.size();
            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1 ; j < n ; j++){
                        mp[nums[i] * nums[j]]++;
                }
            }
            long long ans = 0;
            for(auto it : mp){
                int c = it.second;
                if (c >= 2) {
                    ans += (c * (c - 1)) / 2;
                }
            }
            return ans * 8;
        }
};

int main () {
    
    return 0;
}
