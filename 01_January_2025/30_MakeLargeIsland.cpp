// https://leetcode.com/problems/making-a-large-island/?envType=daily-question&envId=2025-01-31

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        map<int, int> compcells;
        int comp = 1;
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for(int i=0;i<n; i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    comp++;
                    int cnt = 0;
                    vector<pair<int, int>> nodes;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j]=1;
                    while(!q.empty()){
                        auto[x, y] = q.front();
                        q.pop();
                        nodes.push_back({x, y});
                        cnt++;
                        for(int k=0; k<4; k++){
                            int nx=x+dx[k];
                            int ny=y+dy[k];
                            if(nx>=0 && nx<n && ny>=0 && ny<n && vis[nx][ny]==0 && grid[nx][ny]==1){
                                q.push({nx, ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                    for(auto[x, y]: nodes){
                        grid[x][y]=comp;
                    }
                    compcells[comp]=cnt;
                }
            }
        }
    
        vector<vector<int>> newvis(n, vector<int>(n, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!newvis[i][j] && grid[i][j]==0){
                    newvis[i][j]=1;
                    set<int> nbrcomps;
                    int islandsz = 1;
                    for(int k=0; k<4; k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<n){
                            if(nbrcomps.count(grid[nx][ny])==0){
                                nbrcomps.insert(grid[nx][ny]);
                                islandsz+=compcells[grid[nx][ny]];
                            }
                        }
                    }
                    ans = max(ans, islandsz);
                }
            }
        }
        if(ans==0) return n*n;
        return ans;
    }
};

int main () {
    
    return 0;
}
