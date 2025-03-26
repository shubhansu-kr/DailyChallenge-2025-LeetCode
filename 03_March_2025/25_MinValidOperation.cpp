// https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/?envType=daily-question&envId=2025-03-26`

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> ele;
        int r = grid[0][0] % x;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] % x != r) {
                    return -1;
                }
                ele.emplace_back(grid[i][j] - r);
            }
        }
        sort(ele.begin(), ele.end());
        int pivot = ele[ele.size()/2];
        int op = 0;
        for(auto &it: ele){
            op += (abs(it-pivot)/x);
        }
        return op;
    }
};

int main () {
    
    return 0;
}