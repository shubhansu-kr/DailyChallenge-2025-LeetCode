// https://leetcode.com/problems/find-words-containing-character/?envType=daily-question&envId=2025-05-24

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
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> li;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            for(int j=0;j<str.length();j++){
                if(str[j] == x){
                    li.push_back(i);
                    break;
                }
            }
        }
        return li;
    }
};

int main () {
    
    return 0;
}