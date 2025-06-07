// https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/?envType=daily-question&envId=2025-06-07

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
    string clearStars(string s) {
        int n=s.length();
        vector<vector<int> > st(26);
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                for(int j=0;j<26;j++){
                    if(st[j].size()>0){
                        s[st[j].back()]='*';
                        st[j].pop_back();
                        break;
                    }
                }
            }else{
                st[s[i]-'a'].push_back(i);
            }
        }
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}