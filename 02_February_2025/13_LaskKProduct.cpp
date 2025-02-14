// https://leetcode.com/problems/product-of-the-last-k-numbers/?envType=daily-question&envId=2025-02-14

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class ProductOfNumbers {
    vector<int> pre;
    int size =0;
public:
    ProductOfNumbers() {
        pre.push_back(1);
        size=0;
    }
    
    void add(int num) {
        if(num!=0){
            pre.push_back(pre[size]*num);
            size++;
        }
        else{
            pre = {1};
            size=0;
        }
    }
    
    int getProduct(int k) {
        if(k>size){
            return 0;
        }
        return pre[size]/pre[size-k];
    }
};


int main () {
    
    return 0;
}
