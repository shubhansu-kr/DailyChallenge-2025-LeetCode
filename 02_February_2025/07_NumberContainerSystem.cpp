// https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class NumberContainers {
public:
    
    unordered_map<int,int> m;
    unordered_map<int,set<int>> m2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m.find(index)!=m.end())
        {
            int n=m[index];
            m2[n].erase(index);
        }
        m[index]=number;
        m2[number].insert(index);
    }
    
    int find(int number) {
        
        if(m2.find(number)==m2.end())return -1;
        for(int i:m2[number])
        {
            return i;
        }
        return -1;
    }
};
    

int main () {
    
    return 0;
}
