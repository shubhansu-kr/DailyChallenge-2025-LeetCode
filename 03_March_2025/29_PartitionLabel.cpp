// https://leetcode.com/problems/partition-labels/?envType=daily-question&envId=2025-03-30

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> p;
        for (int i = 0; i < s.size(); i++)
        {
            p[s[i]] = i;
        }

        vector<int> res;
        int maxi = 0, prev = -1;
        for (int i = 0; i < s.size(); i++)
        {
            maxi = max(maxi, p[s[i]]);
            if (maxi == i)
            {
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return res;
    }
};

int main () {
    
    return 0;
}