// https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11

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
    bool canConstruct(string s, int k) {
        if(s.size()<k)return 0;
        unordered_map<char,int>mp;
        for(auto it:s)mp[it]++;
        int cnt=0;
        for(auto it:mp){
            if(it.second%2!=0)cnt++;
        }
        if(cnt>k)return 0;
        return 1;
    }
};

int main () {
    
    return 0;
}
