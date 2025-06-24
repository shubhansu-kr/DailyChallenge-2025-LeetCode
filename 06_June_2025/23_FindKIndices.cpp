// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24

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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int size = nums.size(), last = -1;
        for(int i = 0; i < size; i++){
            if(nums[i] == key){
                int start = i - k, end = i + k;
                for(int j = last < start ? start : last + 1; j <= end; j++){
                    if(j < 0 || j >= size) continue;
                    result.push_back(j);
                    last = j;
                }
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}