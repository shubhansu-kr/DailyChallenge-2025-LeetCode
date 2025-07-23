// https://leetcode.com/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2025-07-23

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
    int maximumGain(string s, int x, int y) {
        int score = 0, flag = 0;
        if (x < y) {
            flag = 1;
            reverse(s.begin(), s.end());
        }

        int bCount = 0, aCount = 0, abCount = 0;
        for(auto &it: s){
            if (it == 'a') {
                ++aCount;
            }
            else if (it == 'b') {
                if (aCount) {
                    --aCount;
                    ++abCount;
                }
                else {
                    ++bCount;
                }
            }
            else {
                if (flag) {
                    // x is less than y. Multiply with y first
                    score += ((abCount * y) + (x * min(aCount, bCount)));
                }
                else {
                    score += ((abCount * x) + (y * min(aCount, bCount)));
                }

                abCount = 0, bCount = 0, aCount = 0;
            }
        }

        if (flag) {
            score += ((abCount * y) + (x * min(aCount, bCount)));
        }
        else {
            score += ((abCount * x) + (y * min(aCount, bCount)));
        }

        return score;
    }
};

int main () {
    
    return 0;
}