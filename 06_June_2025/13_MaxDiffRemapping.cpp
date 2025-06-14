// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/?envType=daily-question&envId=2025-06-14

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
    int minMaxDifference(int num) {
        string s = to_string(num);
        string sMax = s, sMin = s;
        char chMax = 'a';
        for(int i = 0; i < s.size(); i++) {
            if(s[i] < '9' && chMax == 'a') 
                chMax = s[i];
            if(s[i] == chMax)
                sMax[i] = '9';
            if(s[0] == s[i])
                sMin[i] = '0';
        }
        return stoi(sMax) - stoi(sMin);
    }
};

int main () {
    
    return 0;
}