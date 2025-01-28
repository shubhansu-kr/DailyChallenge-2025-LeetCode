// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/?envType=daily-question&envId=2025-01-28

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
    int bfs(int ind1,int ind2,int n,int m,vector<vector<int>>&vis,vector<vector<int>>& grid){
        int cost=0;

        vis[ind1][ind2]=1;

        queue<pair<int,int>>q;
        q.push({ind1,ind2});
        
        while(!q.empty()){
            ind1=q.front().first;
            ind2=q.front().second;
            q.pop();
            cost+=grid[ind1][ind2];
            cout<<ind1<<ind2<<endl;
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            for(int i=0;i<4;i++){
                int newid=ind1+dx[i];
                int newid2=ind2+dy[i];
                if(newid<0||newid>=n||newid2<0||newid2>=m||vis[newid][newid2]||grid[newid][newid2]==0){
                    continue;
                }
                q.push({newid,newid2});
                vis[newid][newid2]=1;
            }
        }
        cout<<cost<<endl;
        return cost;

    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
                if(grid[i][j]){
                    maxi=max(bfs(i,j,grid.size(),grid[0].size(),vis,grid),maxi);

                }
            }
        }
        return maxi;
    }
};

int main () {
    
    return 0;
}
