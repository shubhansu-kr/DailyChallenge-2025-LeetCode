// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/?envType=daily-question&envId=2025-07-04

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

typedef long long int ll;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& ops) {
        bitset<1000> bits(k - 1); // Convert (k-1) to 1000-bit binary
        ll ans = 0;

        for (int i = 0; i < ops.size(); i++) {
            if (bits[i] && ops[i] == 1) {
                ans++;
            }
        }

        return 'a' + (ans % 26);

    }
};

int main () {
    
    return 0;
}