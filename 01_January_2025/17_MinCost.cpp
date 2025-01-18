// https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/?envType=daily-question&envId=2025-01-18

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
    typedef pair<int, int> par;
    int minCost(vector<vector<int>> &grid)
    {
        int ret = -1;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        queue<par> q;
        q.push({0, 0});
        grid[0][0]*=-1;
        bool not_end = true;
        while (not_end)
        {
            ret++;
            bool not_all = true;
            while (not_end && not_all)
            {
                not_all = false;
                int n = q.size();
                for (int i = 0; not_end && i < n; i++)
                {
                    par tmp = q.front();
                    if (tmp.first == grid.size() - 1 && tmp.second == grid[0].size() - 1)
                    {
                        not_end = false;
                        break;
                    }
                    q.pop();
                    q.push(tmp);
                    int tx=tmp.first+dx[-1-grid[tmp.first][tmp.second]];
                    int ty=tmp.second+dy[-1-grid[tmp.first][tmp.second]];
                    if(tx>=0&&tx<grid.size()&&ty>=0&&ty<grid[0].size()&&grid[tx][ty]>0)
                    {
                        q.push({tx,ty});
                        not_all = true;
                        grid[tx][ty]*=-1;
                    }
                }
            }
            int n = q.size();
            for (int i = 0; not_end && i < n; i++)
            {
                par tmp = q.front();
                q.pop();
                int tx,ty;
                for(int i=0;i<4;i++)
                {
                    tx=tmp.first+dx[i];
                    ty=tmp.second+dy[i];
                    if(tx>=0&&ty>=0&&tx<grid.size()&&ty<grid[0].size()&&grid[tx][ty]>0)
                    {
                        q.push({tx, ty});
                        grid[tx][ty]*=-1;
                    }
                }
            }
        }
        return ret;
    }
};

int main () {
    
    return 0;
}
