// https://leetcode.com/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-04

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
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < fruits.size(); ++j)
        {
            count[fruits[j]]++;
            if (count.size() > 2)
            {
                if (--count[fruits[i]] == 0) count.erase(fruits[i]);
                i++;
            }
        }
        return j - i;
    }
};

int main () {
    
    return 0;
}