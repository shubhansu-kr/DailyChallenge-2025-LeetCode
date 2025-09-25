// https://leetcode.com/problems/triangle/?envType=daily-question&envId=2025-09-25

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
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> x(m, INT_MAX);
        x[0] = triangle[0][0];
        for (int i = 1; i < m; ++i)
        {
            vector<int> temp(m);
            for (int j = 0; j < i + 1; ++j)
            {
                int up = INT_MAX;
                if (j < i)
                {
                    up = triangle[i][j] + x[j];
                }
                int left = INT_MAX;
                if (j > 0)
                {
                    left = triangle[i][j] + x[j - 1];
                }
                temp[j] = min(up, left);
            }
            x = temp;
        }
        int ans = INT_MAX;
        for (int &a : x)
        {
            ans = min(ans, a);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}