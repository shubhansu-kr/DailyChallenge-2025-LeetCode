#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

vector<int> getDistinctCharacters(int n,string s,vector<vector<int>> q){
    vector<int> a;
    for(auto &x:q){
        if(x[0]==1) s[x[1]-1]=x[2]+'a'-1;
        else{
            set<char> st;
            for(int i=x[1]-1;i<x[2];i++) st.insert(s[i]);
            a.push_back(st.size());
        }
    }
    return a;
}

int main(){
    int n=6;string s="xyzxyz";
    vector<vector<int>> q={{2,2,5},{1,4,26},{1,1,1}, {2,1,6}};
    auto r=getDistinctCharacters(n,s,q);
    for(auto x:r) cout<<x<<" ";
}
