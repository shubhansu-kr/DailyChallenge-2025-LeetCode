// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/?envType=daily-question&envId=2025-01-12

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
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;

        int openCount = 0, unmatchedClose = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') openCount++;
            else unmatchedClose++;
            if (unmatchedClose > openCount) return false;
        }

        int closeCount = 0, unmatchedOpen = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') closeCount++;
            else unmatchedOpen++;
            if (unmatchedOpen > closeCount) return false;
        }

        return true;
    }
};


int main () {
    
    return 0;
}
