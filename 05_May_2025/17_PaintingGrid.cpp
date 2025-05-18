// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/?envType=daily-question&envId=2025-05-18

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
    // 19ms
    int colorTheGrid(int m, int n) {
        vector<int> ms; 
        auto msk = [&](this const auto& msk, int i, int c, int p) -> void {
            if (!i) ms.push_back(c); else for (int j = 1; j < 4; ++j) 
            if (j != p) msk(i - 1, (c << 3) | (1 << j), j);
        }; 
        msk(m, 0, 0);
        int M = 1e9+7, s = size(ms), r = 0; vector<int> dp(s, 1), dp2(s);
        for (int i = 1; i < n; ++i) {
            for (int mask = 0; mask < s; ++mask) {
                int c = 0; for (int m = 0; m < s; ++m) 
                    if (!(ms[m] & ms[mask])) c = (c + dp[m]) % M;
                dp2[mask] = c;
            }
            dp.swap(dp2);
        }
        for (int x: dp) r = (r + x) % M; return r;
    }
};

int main () {
    
    return 0;
}