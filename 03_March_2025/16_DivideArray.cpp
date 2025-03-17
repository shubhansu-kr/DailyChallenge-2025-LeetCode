// https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17

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
    bool divideArray(vector<int>& nums) {
        int arr[501] = {0};
        for(int i: nums){
            arr[i]++;
        }
        for(int i: arr){
            if(i%2 != 0) return false;
        }
        return true;
    }
};

int main () {
    
    return 0;
}
