// https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/?envType=daily-question&envId=2025-08-07

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
    int maxCollectedFruits(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0;

        for (int i = 0; i < n; i++) {
            res += grid[i][i];
        }

        for (int pass = 0; pass < 2; pass++) {
            if (pass == 1) {
                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        swap(grid[i][j], grid[j][i]);
                    }
                }
            }

            vector<int> prev(n, -1), curr(n, -1);
            prev[n - 1] = grid[0][n - 1];

            for(int row = 1; row < n - 1; row++) {
                fill(curr.begin(), curr.end(), -1);
                for (int i = 0; i < n; i++) {
                    if (prev[i] < 0) continue;
                    if (i > 0) 
                        curr[i - 1] = max(curr[i - 1], prev[i] + grid[row][i - 1]);
                    if (i < n - 1) 
                        curr[i + 1] = max(curr[i + 1], prev[i] + grid[row][i + 1]);
                    curr[i] = max(curr[i], prev[i] + grid[row][i]);
                }
                swap(prev, curr);
            }
            res += prev[n - 1];
        }
        return res;
    }
};

int main () {
    
    return 0;
}