// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08

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
    int minimumRecolors(string blocks, int k) {
        int cMin = INT_MAX, count = 0;
        for (int i = 0; i < k; ++i)
        {
            if (blocks[i] == 'W') ++count;
        }
        cMin = min(count, cMin);
        int i = 0, j = k;
        while (j < blocks.size()) {
            if (blocks[i] == 'W') --count;
            if (blocks[j] == 'W') ++count;

            cMin = min(count, cMin);
            ++i, ++j;
        }
        return cMin;
    }
};

int main () {
    
    return 0;
}
