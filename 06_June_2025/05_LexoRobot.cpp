// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/?envType=daily-question&envId=2025-06-06

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
    string robotWithString(string s) {
        int n = s.length();
        string t = "";
        string paper = "";
        vector<char> smallestCharToRight(n); 
        smallestCharToRight[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--) {
            smallestCharToRight[i] = min(s[i], smallestCharToRight[i+1]);
        }

        int i = 0; 
        while(i < n) {
            t.push_back(s[i]);

            char minChar = (i+1 < n) ? smallestCharToRight[i+1] : s[i];

            while(!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }
        while(!t.empty()) {
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};

int main () {
    
    return 0;
}