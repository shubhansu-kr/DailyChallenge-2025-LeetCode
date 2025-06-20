// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/?envType=daily-question&envId=2025-06-20

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
    int maxDistance(string s, int k) {

        int res=INT_MIN;
        int x=0,y=0,adddist=0;

        vector<int> dist;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='N')   y++;
            else if(s[i]=='S')  y--;
            else if(s[i]=='E')  x++;
            else if(s[i]=='W')  x--;

            int temp=abs(0-x)+abs(0-y);
            res=max(res,temp);
            dist.push_back(temp);
        }

        for(int i=1;i<dist.size();i++)
        {
            dist[i]=dist[i]+adddist;
            if(dist[i]<dist[i-1] && k>0)
            {
                k--;
                dist[i]+=2;
                adddist+=2;
            }
            res=max(res,dist[i]);
        }
        return res;
    }
};

int main () {
    
    return 0;
}