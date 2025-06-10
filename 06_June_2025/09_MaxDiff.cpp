// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/?envType=daily-question&envId=2025-06-10

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
    int maxDifference(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int even_min = n, odd_max = 0;
        for (int val: freq) {
            if (val == 0) continue;
            
            if (val % 2 == 0) {
                even_min = min(even_min, val);
            } else {
                odd_max = max(odd_max, val);
            }
        }
        return odd_max - even_min;
    }
};

int main () {
    
    return 0;
}