// https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/?envType=daily-question&envId=2025-10-17

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
    int maxPartitionsAfterOperations(string s, int k) {
        if (k == 26) return 1;
        int n = (int)s.size();
        vector<int> prefixMask(n), prefixDup(n), prefixParts(n);

        int curMask = 0, curDup = 0, curParts = 1;
        for (int i = 0; i < n; ++i) {
            int bit = 1 << (s[i] - 'a');
            curDup |= (curMask & bit);
            curMask |= bit;
            if (__builtin_popcount((unsigned)curMask) > k) {
                curMask = bit;
                curDup = 0;
                ++curParts;
            }
            prefixMask[i] = curMask;
            prefixDup[i] = curDup;
            prefixParts[i] = curParts;
        }

        int best = curParts;
        int sufMask = 0, sufDup = 0, sufParts = 0;
        int fullMaskAll = (1 << 26) - 1;

        for (int i = n - 1; i >= 0; --i) {
            int bit = 1 << (s[i] - 'a');
            sufDup |= (sufMask & bit);
            sufMask |= bit;

            int sufDistinct = __builtin_popcount((unsigned)sufMask);
            if (sufDistinct > k) {
                sufMask = bit;
                sufDup = 0;
                ++sufParts;
                sufDistinct = 1;
            }

            if (sufDistinct == k) {
                bool charRepeatsInSuffix = (bit & sufDup);
                bool charRepeatsInPrefix = (bit & prefixDup[i]);
                bool prefixHasK = (__builtin_popcount((unsigned)prefixMask[i]) == k);
                bool combinedAllLetters = ((prefixMask[i] | sufMask) == fullMaskAll);

                if (charRepeatsInSuffix && charRepeatsInPrefix && prefixHasK && !combinedAllLetters) {
                    best = max(best, sufParts + prefixParts[i] + 2);
                } else if (sufDup) {
                    best = max(best, sufParts + prefixParts[i] + 1);
                }
            }
        }

        return best;
    }
};

int main () {
    
    return 0;
}