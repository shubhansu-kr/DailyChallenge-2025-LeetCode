// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2025-01-14

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
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int,int>mp;
        int count=0;
        vector<int>C;
        for(int i=0;i<n;i++){
            if(mp.find(A[i]) != mp.end())count++;
            mp[A[i]]++;
            if(mp.find(B[i]) != mp.end())count++;
            mp[B[i]]++;
            C.push_back(count);
        }
        return C;
    }
};

int main () {
    
    return 0;
}
