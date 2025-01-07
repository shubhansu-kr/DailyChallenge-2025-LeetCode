// https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07

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
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos){
                    if (find(result.begin(), result.end(), words[i]) == result.end()) {
                        result.push_back(words[i]);
                    }
                    break;
                }
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}
