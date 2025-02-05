// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05

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
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s2.size();j++){
                string copy = s1;
                swap(copy[i] , copy[j]);
                if(copy == s2) return true;
            }
        }
        
        return false;
    }
};

int main () {
    
    return 0;
}
