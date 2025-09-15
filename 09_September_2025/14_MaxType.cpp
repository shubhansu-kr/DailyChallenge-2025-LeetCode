// https://leetcode.com/problems/maximum-number-of-words-you-can-type/?envType=daily-question&envId=2025-09-15

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
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0, flag = 1;
        set<char> p(brokenLetters.begin(), brokenLetters.end());
        for (auto x : text)
        {
            if (x == ' ')
            {
                if (flag)
                {
                    count++;
                }
                else
                {
                    flag = 1;
                }
            }
            if (!flag)
            {
                continue;
            }
            if (p.count(x))
            {
                flag = 0;
            }
        }
        if (flag)
        {
            count++;
        }
        return count;
    }
};

int main () {
    
    return 0;
}