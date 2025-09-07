// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

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
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        ans[0] = -(n * n)+1;
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                ans[i] = ((n * n)-1) - ((n - 2) * (n - 1) / 2);
                break;
            }
            ans[i] = i;
        }

        return ans;
    }
};

int main () {
    
    return 0;
}