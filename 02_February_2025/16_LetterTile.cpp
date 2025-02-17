// https://leetcode.com/problems/letter-tile-possibilities/?envType=daily-question&envId=2025-02-17

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
    int numTilePossibilities(string s) {
        unordered_set<string> st;
        string str = s;
    x:
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j <= s.length() - i; j++)
                st.insert(s.substr(i, j));
        }
        next_permutation(s.begin(), s.end());
        if (s == str)
            return st.size();
        goto x;
    }
};

int main () {
    
    return 0;
}
