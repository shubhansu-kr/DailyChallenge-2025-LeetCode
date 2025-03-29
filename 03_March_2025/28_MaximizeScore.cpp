// https://leetcode.com/problems/apply-operations-to-maximize-score/?envType=daily-question&envId=2025-03-29

#include <bits/stdc++.h>
using namespace std ;

int N = 1e5 + 10;
int M = 1e9 + 7;

vector<bool> arr(N, 0);
vector<int> HP(N, 0);

class Solution {
public:
    void sieve_with_variation() {
        arr[0] = -1;
        arr[1] = -1;
        for (int i = 2; i <= (1e5+1); i++) {

            if (arr[i] == false) {
                HP[i] = i;
                for (int j = (i << 1); j <= (1e5+1); j = j + i) {
                    arr[j] = true;
                    HP[j] = i; 
                }
            }
        }
    }

    int getCoutnDistinctPrimeFactors (int num) {
        int count = 0;
        while( num > 1 ){
            int prime_factor = HP[num] ;
            count ++;
            while( num % prime_factor == 0 ){
                num /= prime_factor ;
            }
        }
        return count;
    }

    int BinaryExpoItr( int a , int b ){
                
                int ans= 1 ;
                
                while( b != 0 ){
                                if( (b&1) != 0 ){
                                                ans = ( ans *1ll* a )%M ;
                                }
                                a = (a*1ll*a)%M;
                                b = b >> 1 ;
                }
                return ans ; 
                
    }

    int maximumScore(vector<int>& nums, int k) {
        sieve_with_variation();
        int n = nums.size();
        vector<int> dpf(n, 0);
        vector<int> nge(n,n);
        vector<int> pge(n,-1);
        vector<pair<int,int>> arr2;
        for (int i = 0; i < n; i++) {
            arr2.push_back({nums[i],i});
            int count = getCoutnDistinctPrimeFactors(nums[i]);
            dpf[i] = count;
        }
        sort (arr2.rbegin(), arr2.rend());
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() and dpf[i] >= dpf[st.top()]) st.pop();
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(i);
        }
        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() and dpf[i] > dpf[st2.top()]) st2.pop();
            if (!st2.empty()) {
                pge[i] = st2.top();
            }
            st2.push(i);
        }
        long long kLeft = k;
        int score = 1;
        for (int i = 0; i < n; i++) {
            if (kLeft <= 0) break;
        auto p = arr2[i];
        int ele = p.first;
        int idx = p.second;
        long long totalSub = (idx - (pge[idx]+1) + 1) *1ll* ((nge[idx]-1) - idx + 1);
        long long canUse = min(kLeft, totalSub);
        kLeft = kLeft - canUse;
        int getScore =  BinaryExpoItr(ele, canUse);
        score = ((score) * 1ll * (getScore)) % M;
        }
        return score;
    }
};

int main () {
    
    return 0;
}