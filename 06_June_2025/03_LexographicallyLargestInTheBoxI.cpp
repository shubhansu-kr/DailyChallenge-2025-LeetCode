//  https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/?envType=daily-question&envId=2025-06-04

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
    string answerString(string word, int numFriends) {
        if(numFriends == 1) return word ;
        int window_sz = word.length() - numFriends + 1 ;
        string res = "" ;
        vector<vector<int>> m(26) ;
        char check = '0' ;
        for(int i = 0 ; i < word.length() ; i++){
            m[word[i]-'a'].push_back(i) ;
            if(word[i]>check) check = word[i] ;
        }
        for(auto &x : m[check-'a']){
            int j = min({x + window_sz - 1, (int)word.length()-1}) ;
            int i = x ;
            string check = word.substr(i,j-i+1) ;
            if(check > res) res = check ;
        }
        return res ;
    }
};

int main () {
    
    return 0;
}