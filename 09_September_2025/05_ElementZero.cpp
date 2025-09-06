// https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/?envType=daily-question&envId=2025-09-06

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
    long long operation(long long l, long long r) {
        long long L = 1;
        long long R = 3;

        long long start = max(L, l);
        long long end = min(R, r);
        long long s = 1;
        long long op = 0;

        while (1) {
            if (start >
                end) {

            } else {
                long long el = end - start + 1;
                op += s * el;
            }
            L = L * 4;
            R = 4 * L - 1;
            if (L > r)
                break;

            start = max(L, l);
            end = min(R, r);
            s += 1;
        }
        return (op + 1) / 2;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;
        for (auto& it : queries) {
            long long l = it[0];
            long long r = it[1];
            total += operation(l, r);
        }
        return total;
    }
};

int main () {
    
    return 0;
}