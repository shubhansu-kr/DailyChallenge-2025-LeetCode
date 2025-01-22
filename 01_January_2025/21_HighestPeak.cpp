// https://leetcode.com/problems/map-of-highest-peak/?envType=daily-question&envId=2025-01-22

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
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> height(n,(vector<int>(m,-1)));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){    
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int currHeight=0;
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(auto [dx,dy]:directions){
                int newrow=row+dx;
                int newcol=col+dy;
                if(newrow<n&&newcol<m&&newcol>=0&&newrow>=0){
                    if(height[newrow][newcol]==-1){
                        height[newrow][newcol]=height[row][col]+1;
                        q.push({newrow,newcol});
                    }
                    
                }
            }
        }
        return height;
    }
};

int main () {
    
    return 0;
}
