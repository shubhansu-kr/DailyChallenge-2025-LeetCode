// https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13

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
    int minimumLength(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char,int> count;
        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        for(auto it: count){
            if(it.second<=2){
                ans+=it.second;
            }
            else if(it.second%2==0){
                ans+=2;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}
