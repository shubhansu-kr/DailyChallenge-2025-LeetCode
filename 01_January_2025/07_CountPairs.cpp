// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-08

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
    bool isPrefixAndSuffix(string &str1, string &str2) {
        int n = str2.length(), k = str1.length();
        return n >= k && str2.find(str1) == 0 && str2.rfind(str1) == (n - k);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n = words.size();
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = i+1; j < n; ++j) {
                ans += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return ans;
    }
};

int main () {
    
    return 0;
}
