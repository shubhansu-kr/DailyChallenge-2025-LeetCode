// https://leetcode.com/problems/minimize-xor/?envType=daily-question&envId=2025-01-15

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
    int minimizeXor(int num1, int num2) {
        vector<int> v(32, 0); 
        int temp = num1;
        int it = 0;

        while (temp > 0) {
            v[it] = (temp & 1);
            temp = temp >> 1;
            it++;
        }

        int ans = 0;
        int n = v.size() - 1;
        int count = __builtin_popcount(num2);

        for (int i = n; i >= 0; i--) {
            if (v[i] == 1) {
                if (count > 0) {
                    ans += (1 << i); 
                    count--;
                } else {
                    v[i] = -1; 
                }
            }
        }

        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 0 && count > 0) {
                ans += (1 << i); 
                count--;
            }
            if (count <= 0) break; 
        }

        return ans;
    }
};

int main () {
    
    return 0;
}
