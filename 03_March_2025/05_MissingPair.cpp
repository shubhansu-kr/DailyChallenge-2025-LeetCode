// https://leetcode.com/problems/find-missing-and-repeated-values/?envType=daily-question&envId=2025-03-06

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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<int>f(n*n+1, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                f[grid[i][j]]+=1;
            }
        }

        vector<int>ans(2, 0);

        for(int i=1; i<=n*n; i++){
            if(f[i]==0) ans[1]=i;
            else if(f[i]==2) ans[0]=i;
        }

        return ans;        
    }
};

int main () {
    
    return 0;
}
