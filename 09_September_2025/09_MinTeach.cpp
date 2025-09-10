// https://leetcode.com/problems/minimum-number-of-people-to-teach/?envType=daily-question&envId=2025-09-10

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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;
        for(auto& friends : friendships){
            int u = friends[0] - 1;
            int v = friends[1] - 1;
            unordered_set<int> langSet(languages[u].begin(),languages[u].end());
            bool canTalk = false;
            for(auto& lang : languages[v]){
                if(langSet.count(lang)){
                    canTalk = true;
                    break;
                }
            }
            if(!canTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }
        vector<int> language(n+1,0);
        int maxKnownLang = 0;
        for(int user : sadUsers){
            for(int lang : languages[user]){
                language[lang]++;
                maxKnownLang = max(maxKnownLang,language[lang]);
            }
        }
        return sadUsers.size() - maxKnownLang;
    }
};

int main () {
    
    return 0;
}