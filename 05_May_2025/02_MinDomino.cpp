// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/?envType=daily-question&envId=2025-05-03

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
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int c=tops[0];int v=1;int count=0;int count1=0;//map<int,int>mp;
            for(int i=1;i<tops.size();i++){
            if(tops[i]==c){
            v++;}
            else{
            v--;}
            if(v==0){
            v=1;
            c=tops[i];}
            //mp[tops[i]]++;

            }
            int x=0;
            //cout<<c<<endl;
            for(int i=0;i<tops.size();i++){
            if(tops[i]==c)
            x++;
            }
            int m=1;int k=bottoms[0];
            for(int i=0;i<bottoms.size();i++){
            if(bottoms[i]==k){
            m++;}
            else{
            m--;}
            if(m==0){
            m=1;
            k=bottoms[i];}
            //mp[bottoms[i]]++;
            }
            
            //cout<<j<<endl;
            int j=0;
            for(int i=0;i<bottoms.size();i++){
            if(bottoms[i]==k)
            j++;
            }
            if(x>j){
            for(int i=0;i<tops.size();i++){
            if(tops[i]!=bottoms[i]&&bottoms[i]==c){
                count++;
                
            }
            if(tops[i]!=c&&bottoms[i]!=c)
            return -1;
            }
            return count;
            }
            else{
            for(int i=0;i<bottoms.size();i++){
            if(tops[i]!=bottoms[i]&&tops[i]==k){
                count1++;
                
            }
            if(tops[i]!=k&&bottoms[i]!=k){
                return -1;
            }
            }
            return count1;
            }
        
            return -1;
    }
};

int main () {
    
    return 0;
}