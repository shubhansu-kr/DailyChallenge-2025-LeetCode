// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

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
    int countPalindromicSubsequence(string s) {
        int result = 0;
        int firstIndex[26] = {[0 ... 25] = INT_MAX};
        int lastIndex[26] = {};

        for (int i = 0; i < s.size(); ++i) {
            firstIndex[s[i] - 'a'] = min(firstIndex[s[i] - 'a'], i);
            lastIndex[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; ++i)
            if (firstIndex[i] < lastIndex[i])
                result += unordered_set<char>(begin(s) + firstIndex[i] + 1, begin(s) + lastIndex[i]).size();
        return result;
    }
};

int main () {
    
    return 0;
}
