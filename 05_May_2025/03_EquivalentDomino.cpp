// https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=daily-question&envId=2025-05-04

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
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mp;
        for(int i=0; i<dominoes.size(); ++i){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            string s;
            if(a<=b){
                s = to_string(a) + to_string(b);
            }else{
                s= to_string(b) + to_string(a);
            }
            mp[s]++;
        }
        int count = 0;
        for(auto iter=mp.begin(); iter!=mp.end();++iter){
            int size = iter->second;
            count += (size*(size-1))/2;
        }
        return count;
    }
};

int main () {
    
    return 0;
}