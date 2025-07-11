// https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-07-11

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

#define ll long long
#define pi pair<ll,ll>

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& A) {
        vector<int> roomcnt(n,0);
        set<int> s;
        priority_queue<pi,vector<pi>,greater<pi>> q;
        sort(A.begin(),A.end());
        int m=A.size();
        for(int i=0;i<n;i++){
            s.insert(i);
        }
        for(int i=0;i<m;i++){
            ll start=A[i][0];
            ll end=A[i][1];
            while(q.size()>0 && q.top().first<=start){
                int room=q.top().second;
                q.pop();
                s.insert(room);
            }
            if(s.size()==0){
                pair<ll,ll> p=q.top();
                q.pop();
                ll dif=end-start;
                start=p.first;
                end=start+dif;
                s.insert(p.second);
            }
            auto it=s.begin(); 
            roomcnt[*it]++;
            q.push({end,*it});
            s.erase(*it);
        }
        int ans=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<roomcnt[i]){
                maxi=roomcnt[i];
                ans=i;
            }
        }
        return ans;
    }
};

int main () {
    
    return 0;
}