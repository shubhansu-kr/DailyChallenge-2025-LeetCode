// https://leetcode.com/problems/shortest-common-supersequence/?envType=daily-question&envId=2025-02-28

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
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 1; i <= n1; ++i)
            for (int j = 1; j <= n2; ++j)
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        int len = dp[n1][n2];
        string ans;
        while (n1 && n2){
            if (str1[n1 - 1] == str2[n2 - 1]){ans.push_back(str1[n1 - 1]);--n1, --n2;}
            else{if (dp[n1 - 1][n2] > dp[n1][n2 - 1]){ans.push_back(str1[--n1]);}else{ans.push_back(str2[--n2]);}}
        }
        if (n1) while(n1) ans.push_back(str1[--n1]);
        if (n2) while(n2) ans.push_back(str2[--n2]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main () {
    
    return 0;
}
