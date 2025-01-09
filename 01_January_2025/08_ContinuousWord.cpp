// https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09

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
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            ++count; 
            for (int j = 0; j < pref.size(); j++)
            {
                if (pref[j] != words[i][j])
                {
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};

int main () {
    
    return 0;
}
