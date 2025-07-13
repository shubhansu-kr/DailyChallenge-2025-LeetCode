#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

long getPages(vector<int> pages, vector<int> threshold) {
    vector<pair<int, int>> printers;
    for (size_t i = 0; i < pages.size(); i++) {
        printers.emplace_back(pages[i], threshold[i]);
    }
    
    sort(printers.begin(), printers.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    reverse(printers.begin(), printers.end());
    
    vector<pair<int, int>> operational;
    long total_pages = 0;
    
    for (const auto& printer : printers) {
        int p = printer.first;
        int t = printer.second;
        
        operational.emplace_back(p, t);
        total_pages += p;
        
        int op_count = operational.size();
        
        vector<pair<int, int>> new_operational;
        for (const auto& prt : operational) {
            if (prt.second > op_count) {
                new_operational.push_back(prt);
            }
        }
        operational = move(new_operational);
    }
    
    return total_pages;
}

int main() {
    vector<int> pages =  {4, 1, 5, 2, 3};
    vector<int> threshold = {3, 3, 2, 3, 3};

    cout << getPages(pages, threshold) << endl ;
    return 0;
}
