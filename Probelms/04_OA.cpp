#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int optimizeInventory(vector<int> inventoryAdjustments) {
    long long s=0,c=0,z=0;
    vector<int> neg;
    for(int x:inventoryAdjustments) {
        if(x>0) s+=x,c++;
        else if(x==0) z++;
        else neg.push_back(x);
    }
    if(!c) return 0;
    c+=z;
    sort(neg.rbegin(),neg.rend());
    for(int x:neg) if(s+x>0) s+=x,c++; else break;
    return c;
}

int main() {
    // Test Case 1
    vector<int> tc1 = {6, -5, 3, -7, 2, -2};
    cout << "Test Case 1: " << optimizeInventory(tc1) << endl; // Expected: 5

    // Test Case 2
    vector<int> tc2 = {-1, -2, 3, 4};
    cout << "Test Case 2: " << optimizeInventory(tc2) << endl; // Expected: 2

    // Test Case 3
    vector<int> tc3 = {1, -1, 1, -1, 1};
    cout << "Test Case 3: " << optimizeInventory(tc3) << endl; // Expected: 5

    // Test Case 4
    vector<int> tc4 = {-3, -2, -1};
    cout << "Test Case 4: " << optimizeInventory(tc4) << endl; // Expected: 0

    // Test Case 5
    vector<int> tc5 = {5, -3, -4};
    cout << "Test Case 5: " << optimizeInventory(tc5) << endl; // Expected: 3

    return 0;
}