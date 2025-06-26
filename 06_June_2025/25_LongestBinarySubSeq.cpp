// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/?envType=daily-question&envId=2025-06-26

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
    int longestSubsequence(string s, int k) {
        int len = 0;
        long long ans = 1;
        int n = s.size();
        long long curr = 0;

        for(int i=n-1;i>=0;i--){
            int num=s[i]-'0';
            curr+=num*ans;
            if(curr<=k) len+=1;
            if(curr>k && s[i]=='0') len++;
            if(ans<=k) ans=ans*2;
        }
        return len;
    }
};

int main () {
    
    return 0;
}