// https://leetcode.com/problems/design-movie-rental-system/?envType=daily-question&envId=2025-09-21

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const { 
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};
class MovieRentingSystem {
    unordered_map<pair<int, int>, int, pair_hash> mp; 
    set<pair<int,pair<int,int>>>rented;
    unordered_map<int, set<pair<int,int>>>ms;
    int n;
public:
    MovieRentingSystem(int size, vector<vector<int>>& entries) {
        n = size;
        for(auto e:entries){
            int s = e[0],m = e[1], p = e[2];
            mp[{s,m}] = p; 
            ms[m].insert({p,s});
        }
    }
    
    vector<int> search(int movie) {
        vector<int>ans;
       
        for(auto &ps : ms[movie]) {
            if(ans.size() == 5) break;
            ans.push_back(ps.second); 
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
         int p = mp[{shop,movie}];
        ms[movie].erase({p,shop});
        rented.insert({p,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
       int p = mp[{shop,movie}];
        rented.erase({p,{shop,movie}});
        ms[movie].insert({p,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>ans;
        for(auto i:rented){
            if(ans.size()<5){
                ans.push_back({i.second.first,i.second.second});
            }
            else break;
        }
        return ans;
    }
};

int main () {
    
    return 0;
}