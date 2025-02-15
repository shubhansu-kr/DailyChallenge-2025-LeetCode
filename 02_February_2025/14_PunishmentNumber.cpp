// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/?envType=daily-question&envId=2025-02-15

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

    bool check_is_it_valid_str(string num, int pos, int prev, int sum, int n, int noo){
        if (pos >= n){
            if (noo == (sum + prev)) return true;
            return false;
        }
        int pick = check_is_it_valid_str(num, pos + 1, prev*10 + (num[pos] - '0'), sum, n, noo);
        int not_pick = check_is_it_valid_str(num, pos + 1, (num[pos] - '0'), sum + prev, n, noo);
        return pick || not_pick;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++){
            string num = to_string(i * i);
            int len = num.length();
            if (check_is_it_valid_str(num, 0, 0, 0, len, i)){
            ans += i*i;
            }
        }   
        return ans;
    }
};

int main () {
    
    return 0;
}
