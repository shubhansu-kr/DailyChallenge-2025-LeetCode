// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-05-13

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    long mod = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        array<int, 26> counts{};
        for (char c : s) counts[c - 'a']++;
        for (int z = 25, a = 0; t--; z = z ? z - 1 : 25, a = a ? a - 1 : 25)
            counts[a] += counts[z] %= mod;
        return accumulate(counts.begin(), counts.end(), 0l) % mod;
    }
};

int main () {
    
    return 0;
}