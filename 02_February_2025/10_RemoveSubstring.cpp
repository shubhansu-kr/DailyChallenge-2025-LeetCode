// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11

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
    string removeOccurrences(string s, string part) {
        while (true)
        {
            int index = s.find(part);
            if (index == string::npos)
            {
                break;
            }
            s.erase(index, part.length());
        }
        return s;
    }
};

int main () {
    
    return 0;
}
