// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/?envType=daily-question&envId=2025-03-11

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
    int numberOfSubstrings(string s) {
        int n=s.length();
        int result=0;
        vector<int>mpp(3,0);
        int i=0;
        int j=0;
        while(j<n)
        {
            char ch=s[j];
            mpp[ch-'a']++;
            while(mpp[0]>0 && mpp[1]>0 && mpp[2]>0)
            {
                result+=(n-j);
                mpp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return result;

        
    }
};

int main () {
    
    return 0;
}
