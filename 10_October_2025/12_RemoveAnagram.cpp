// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

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
    vector<string> removeAnagrams(vector<string>& a) {
        map<char,int>mpp1;
        map<char,int>mpp2;
        for(auto it:a[0]){mpp1[it]++;}
        vector<string>ans;
        ans.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            for(auto it:a[i]){mpp2[it]++;}
            if(mpp1!=mpp2){ans.push_back(a[i]);}
            mpp1 = mpp2;
            mpp2.clear();
        }
        return ans; 
    }
};

int main () {
    
    return 0;
}