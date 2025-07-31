// https://leetcode.com/problems/bitwise-ors-of-subarrays/?envType=daily-question&envId=2025-07-31

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
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>oris;
        unordered_set<int>curr,prev;
        for(auto it:arr){
            curr.clear();
            curr.insert(it);
            for(auto it2:prev){
                curr.insert(it|it2);
            }
            prev=curr;
            for(auto it2:prev){
                oris.insert(it2);
            }
        }
        return oris.size();
    }
};

int main () {
    
    return 0;
}