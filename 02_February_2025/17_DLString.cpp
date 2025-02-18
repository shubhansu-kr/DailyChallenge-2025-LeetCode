// https://leetcode.com/problems/construct-smallest-number-from-di-string/?envType=daily-question&envId=2025-02-18

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
    string res;
    bool vis[10]={false};
    void solve(string pattern,string &ans)
    {
        if(ans.size()==pattern.size()+1)
        {
            if((res.size()==0)||res>ans)
            {
                res=ans;
            }
            return;
        }
        for(int i=1;i<=9;i++){
            
            if(vis[i]==true)
                continue;

            char ch='0'+i;
            
            cout<<ans<<" ";
            if(ans.empty()
                || (pattern[ans.size()-1]=='I' && ans.back()<'0'+i)
                ||(pattern[ans.size()-1]=='D' && ans.back()>'0'+i)){
                    
                ans.push_back(ch);
                    vis[i]=true;
                solve(pattern,ans);
                    vis[i]=false;
                ans.pop_back();  
            }
        }
    }

    string smallestNumber(string pattern) {
        string ans="";
        solve(pattern,ans);
        return res;
    }
};

int main () {
    
    return 0;
}
