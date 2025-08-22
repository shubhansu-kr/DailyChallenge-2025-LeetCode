// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/?envType=daily-question&envId=2025-08-22

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
    static int minimumArea(vector<vector<int>>& grid) {
        const int n=grid.size(), m=grid[0].size();
        int iMin=1000, iMax=-1, jMin=1000, jMax=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) continue;
                iMin=min(iMin, i);
                iMax=max(iMax, i);
                jMin=min(jMin, j);
                jMax=max(jMax, j);
            }
        }
        return (iMax-iMin+1)*(jMax-jMin+1);
    }
};

int main () {
    
    return 0;
}