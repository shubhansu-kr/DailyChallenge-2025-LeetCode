// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/?envType=daily-question&envId=2025-06-05

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
    int par[26];
    int find(int x)
    {
        if (par[x] == -1) return x;
        return par[x] = find(par[x]);
    }
    void Union(int x, int y)
    {
        x = find(x);y = find(y);
        if (x != y) par[max(x, y)] = min(x, y);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        memset(par, -1, sizeof(par));
        for (auto i = 0; i < s1.size(); ++i) Union(s1[i] - 'a', s2[i] - 'a');
        for (auto i = 0; i < baseStr.size(); i++) baseStr[i] = find(baseStr[i] - 'a') + 'a';
        return baseStr;
    }
};

int main () {
    
    return 0;
}