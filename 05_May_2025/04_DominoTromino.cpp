// https://leetcode.com/problems/domino-and-tromino-tiling/?envType=daily-question&envId=2025-05-05

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
    int numTilings(int n) {
        long long g[1001], u[1001];
        int mod = 1000000007;
        g[0] = u[0] = 0;
        g[1] = u[1] = 1;
        g[2] = u[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            u[i] = (u[i - 1] + g[i - 1]) % mod;
            g[i] = (g[i - 1] + g[i - 2] + 2 * u[i - 2]) % mod;
        }
        return g[n] % mod;
    }
};

int main () {
    
    return 0;
}