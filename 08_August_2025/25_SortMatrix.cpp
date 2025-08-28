// https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
    void func(int i, int j , vector<vector<int>> &grid, int flag){
        int n = grid.size();
        int a = i, b = j;
        vector<int> ans;
        while(i<n && j<n){
            ans.push_back(grid[i][j]);
            i++, j++;
        }
        if(flag==1)sort(ans.begin(), ans.end());
        else if(flag ==2) sort(ans.begin(), ans.end(), greater<int>());
        for(int x = 0; x<ans.size(); x++){
            grid[a][b] = ans[x];
            a++, b++;
        }
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0; i<n; i++){
            func(i,0,grid,2);
        }
        for(int j = 1; j<n; j++){
            func(0, j, grid,1);
        }
        return grid;
    }
};

int main () {
    
    return 0;
}