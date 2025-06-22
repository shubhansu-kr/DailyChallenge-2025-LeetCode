// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-22

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
    vector<string> divideString(string &s, int k, char fill) {
        auto [q, r]=div(s.size(), k);
        vector<string> ans(q+(r>0)); 
        for (int i=0; i<q; i++){
            ans[i]=s.substr(i*k, k);
        }
        if (r>0){
            ans.back()=s.substr(q*k);
            ans.back()+=string(k-r, fill);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}