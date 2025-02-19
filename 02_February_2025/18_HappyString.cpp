// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19

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
    string getHappyString(int n, int k) {
        string res;
        backtrack(n, k, "", ' ', res);
        return res;
    }

private:
    void backtrack(int n, int &k, string cur, char lastChar, string &res) {
        if (cur.size() == n) {
            if (--k == 0) res = cur;
            return;
        }
        for (char c : {'a', 'b', 'c'}) {
            if (c != lastChar && res.empty())  
                backtrack(n, k, cur + c, c, res);
        }
    }
};

int main () {
    
    return 0;
}
