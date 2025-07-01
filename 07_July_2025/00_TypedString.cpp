// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    bool check(string word){
        for(int i=0;i<word.size()-1;i++){
            if(word[i]==word[i+1]) return true;
        }
        return false;
    }
public:
    int possibleStringCount(string word) {
        int ans=1;
        int i=0;
        while(i+1<word.size()){
            bool flag=true;
            while(flag && (i+1)<word.size()){
                if(word[i]==word[i+1]) ans++;
                else flag=0;
                i++;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}