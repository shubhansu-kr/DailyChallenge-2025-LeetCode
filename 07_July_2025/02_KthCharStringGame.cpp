// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-07-03

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
    char kthCharacter(int k) {
        string ans("a");
        int n = ans.size();
        while (n < k) {
            for (int i = 0; i < n; i++) {
                ans+= 'a' + ((ans[i] + 1) % 'a');
            }
            n = ans.size();
        }
        return ans[k-1];
    }
};

int main () {
    
    return 0;
}