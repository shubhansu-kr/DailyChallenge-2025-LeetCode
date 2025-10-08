// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/?envType=daily-question&envId=2025-10-08

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int a : spells)
        {
            long need = (success + a - 1) / a;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};

int main () {
    
    return 0;
}