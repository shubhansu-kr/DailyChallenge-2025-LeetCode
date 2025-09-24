// https://leetcode.com/problems/fraction-to-recurring-decimal/?envType=daily-question&envId=2025-09-24

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
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator==0) return "0";
        
        string ans;
        // Handle sign
        if ((numerator<0)^(denominator< 0)) ans+='-';
        // Convert to long to avoid overflow (INT_MIN)
        long long num=abs((long long)numerator);
        long long den=abs((long long)denominator);

        long long q=num/den;
        long long r=num%den;
        ans+=to_string(q);

        if (r==0) return ans;

        ans+= '.';
        unordered_map<long long, int> mp;
        string frac;

        for(int i=0; r != 0; i++) {
            if (mp.count(r)) {
                frac.insert(mp[r], "(");
                frac+= ')';
                break;
            }
            mp[r]=i;
            r*=10;
            frac+=('0'+r/den);
            r%=den;
        }

        return ans+frac;
    }
};

int main () {
    
    return 0;
}