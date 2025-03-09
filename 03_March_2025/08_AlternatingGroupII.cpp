// https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09

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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        int i=0,j=1,n=colors.size();
        while(j<n+k-1) 
        {
            if(colors[j%n]==colors[(j-1)%n]) 
            {
                if(j-i>=k)
                ans+=(j-i-k+1);
                i=j;
            }
            j++;
        }
        if(j-i>=k)
        ans+=(j-i-k+1);
        return ans;
        
    }
};

int main () {
    
    return 0;
}
