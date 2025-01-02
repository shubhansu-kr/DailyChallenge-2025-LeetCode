// https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02

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
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>store;
        unordered_map<char, int>mpp;
        mpp['a']=1,mpp['e']=1,mpp['i']=1,mpp['o']=1,mpp['u']=1;
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(mpp[words[i][0]]==1 && mpp[words[i][words[i].length()-1]]==1) count++;
            store.emplace_back(count);
        }
        int m=queries.size();
        vector<int>result;
        for(int i=0;i<m;i++){
            int a=queries[i][0],b=queries[i][1];
            if(a==0) result.emplace_back(store[b]);
            else{
                result.emplace_back(store[b]-store[a-1]);
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}
