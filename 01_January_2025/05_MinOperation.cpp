// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/?envType=daily-question&envId=2025-01-06

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
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length());
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i)
        {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i)
        {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};

int main () {
    
    return 0;
}
