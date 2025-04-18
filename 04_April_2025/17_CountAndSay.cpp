// https://leetcode.com/problems/count-and-say/?envType=daily-question&envId=2025-04-18

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string say(string s){
        string ans = "";
        int count = 1, i = 1;
        for (i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i-1]){++count;}
            else{
                ans.push_back('0'+count);
                ans.push_back(s[i-1]);
                count = 1;
            }
        }
        ans.push_back('0'+count);
        ans.push_back(s[i-1]);
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i)
        {
            ans = say(ans);            
        }
        return ans;
    }
};

int main () {
    
    return 0;
}