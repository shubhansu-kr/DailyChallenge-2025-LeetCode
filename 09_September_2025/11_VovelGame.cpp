// https://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12

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
    bool doesAliceWin(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                count++;
            }
        }
        if(count==0){
            return false;
        }
        return true;
    }
};

int main () {
    
    return 0;
}