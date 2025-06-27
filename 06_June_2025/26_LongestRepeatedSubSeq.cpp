// https://leetcode.com/problems/longest-subsequence-repeated-k-times/?envType=daily-question&envId=2025-06-27

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
private:
    bool checkKtimes(string s, string t, int k) {
        const int tn = t.length();
        int pos = 0;
        for (char c : s) {
            pos += (c == t[pos]);
            if (pos == tn) {
                pos = 0;
                if (--k == 0) return true;
            }
        }
        return false;
    }
public:
    string longestSubsequenceRepeatedK(string olds, int k) {
        const int n = olds.length();
        vector<int> freq(26, 0);
        for (char c : olds) ++freq[c - 'a'];
        string s = "";
        for (char c : olds) {
            if (freq[c - 'a'] < k) continue;
            s += c;
        }
        queue<string> q;
        vector<char> candidates;
        for (int i = 25; i >= 0; --i) { 
            if (freq[i] < k) continue;
            q.push(string(1, i+'a'));
            candidates.emplace_back(i + 'a');
        }

        string ans = "";
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            if (curr.length() > ans.length()) ans = curr;
            for (char c : candidates) {
                string next = curr + c;
                if (checkKtimes(s, next, k)) q.push(next);
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}