// https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21

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
    string makeFancyString(string s) {
        string ans = "";
        ans.push_back(s[0]);
        int n = s.size(),cnt = 1;
        for(int i=1;i<n;i++){
            if(s[i] == ans.back()){
                cnt++;
                if(cnt < 3)ans.push_back(s[i]);
            }
            else{
                cnt = 1;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}