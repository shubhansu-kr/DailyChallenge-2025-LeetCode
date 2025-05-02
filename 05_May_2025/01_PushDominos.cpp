// https://leetcode.com/problems/push-dominoes/?envType=daily-question&envId=2025-05-02

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
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res = "";
        for (int i = 0, j = 1; j < dominoes.length(); ++j) {
            if (dominoes[j] == '.') continue;
            int middle = j - i - 1;
            if (i > 0) res += dominoes[i];
            if (dominoes[i] == dominoes[j]) res += string(middle, dominoes[i]);
            else if (dominoes[i] == 'L' && dominoes[j] == 'R') res += string(middle, '.');
            else res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
            i = j;
        }
        return res;
    }
};

int main () {
    
    return 0;
}