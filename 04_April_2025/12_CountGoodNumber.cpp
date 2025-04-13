// https://leetcode.com/problems/count-good-numbers/?envType=daily-question&envId=2025-04-13

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2; 
        long long oddCount = n / 2;  

        long long evenWays = modPow(5, evenCount, MOD);
        long long oddWays = modPow(4, oddCount, MOD);

        return (evenWays * oddWays) % MOD;
    }
};

int main () {
    
    return 0;
}