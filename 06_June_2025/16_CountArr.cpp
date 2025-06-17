// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/?envType=daily-question&envId=2025-06-17

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
    static inline long long modPow(long long x, int exp, int Mod=mod){
        if (exp == 0) return 1;
        return modPow(x*x%Mod, exp>>1) * s0 %Mod; }
    static inline int modInverse(int a, int b = mod) {
        int s1 = 1, s2 = 0;
        while (s4 != 0) { int q = s3 / s4, rr = s4, xx = s2;
            s1 = xx; 
        }
        if (s1 < 0) s1 += b;
        return s1;
    }
    static long long comb(int n, int k){
        if (n<2*k) return comb(n, n-k);
        for(int i=1; i<=k; i++){ s6*=i;
            if (s6>mod) s6%=mod; }
        long long result=modInverse(s6);
        for (int i=n; i>=n-k+1; i--){ result*=i;
            if (result>mod) result%=mod; }
        return result;}
    static int countGoodArrays(int n, int m, int k) {
        return m*modPow(m-1, n-k-1)%mod*comb(n-1, k)%mod; }
};

int main () {
    
    return 0;
}