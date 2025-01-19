// Find the max beauty

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

    // You are given a n*n matrix with numbers in each cell denoting its value.
    // Start your journey from (0,0) and go to (n-1, n-1)
    // You can move one right, or one down or one up in one move. 
    // You cannot visit any cell twice

    // Find the path with max possible beauty. Beauty of the path is sum of values of all the cell it goes through.

    // constraint : 1 <= n <= 10^3 && -10^3 <= a[i][j] <= 10^3



int dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& memo, vector<vector<bool>>& visited) {
    int n = a.size();

    if (i == n - 1 && j == n - 1) return a[i][j];

    if (memo[i][j] != INT_MIN) return memo[i][j];

    visited[i][j] = true; 
    int maxBeauty = INT_MIN;

    if (i - 1 >= 0 && !visited[i - 1][j])
        maxBeauty = max(maxBeauty, dfs(i - 1, j, a, memo, visited));

    if (j + 1 < n && !visited[i][j + 1])
        maxBeauty = max(maxBeauty, dfs(i, j + 1, a, memo, visited));

    if (i + 1 < n && !visited[i + 1][j])
        maxBeauty = max(maxBeauty, dfs(i + 1, j, a, memo, visited));

    visited[i][j] = false; 
    return memo[i][j] = a[i][j] + maxBeauty;
}

int GetMaximumBeauty(int n, vector<vector<int>> a) {
    vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    return dfs(0, 0, a, memo, visited);
}

int main() {
    vector<vector<int>> matrix{{1, 1, 1},
                                {1, 1, 1},
                                {1, 1, 3}};
    
    // Call the getMaxPathSum function and print the result
    cout << GetMaximumBeauty(3, matrix);

    return 0;
}

