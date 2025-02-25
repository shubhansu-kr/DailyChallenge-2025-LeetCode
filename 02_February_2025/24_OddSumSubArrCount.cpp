// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/?envType=daily-question&envId=2025-02-25

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
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;  
        int sum = 0, result = 0;
    
        for (int num : arr) {
            sum ^= num;  
            result = (result + ((sum & 1) ? evenCount : oddCount)) % MOD;
            (sum & 1) ? oddCount++ : evenCount++;
        }
    
        return result;
    }
};

int main () {
    
    return 0;
}
