// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10

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
    string clearDigits(string s) {
        vector<bool> mark(s.size(),false);
        for(int i = 0 ; i < s.size() ; i++){
            if(isdigit(s[i])){
                if(i > 0){
                    for(int j = i -1 ; j >= 0;j--){
                        if(!mark[j] && !isdigit(s[j])){
                            mark[j] = true;
                            break;
                        }
                    }
                }
                mark[i] = true;
            }
        }

        string res = "";
        for(int i = 0 ; i < s.size();i++){
            if(!mark[i])
                res += s[i];
        }

        return res;
    }
};

int main () {
    
    return 0;
}
