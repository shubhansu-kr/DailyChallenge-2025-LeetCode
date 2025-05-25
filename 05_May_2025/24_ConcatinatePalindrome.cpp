// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/?envType=daily-question&envId=2025-05-25

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
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        int ans = 0;

        for (auto w : words)
        {
            int a = w[0] - 'a';
            int b = w[1] - 'a';

            if (count[b][a])
            {
                ans += 4;
                count[b][a]--; 
            }
            else count[a][b]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (count[i][i])
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}