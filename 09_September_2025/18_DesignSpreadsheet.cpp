// https://leetcode.com/problems/design-spreadsheet/?envType=daily-question&envId=2025-09-19

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Spreadsheet {
    unordered_map<string, int> cells;

    bool isNumber(const string &s) {
        return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
    }

public:
    Spreadsheet(int rows) {
        
    }

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells[cell] = 0;
    }

    int getValue(string formula) {
        int sum = 0;
        int i = 1; // Skip '='
        while (i < formula.size()) {
            int j = i;
            while (j < formula.size() && formula[j] != '+') j++;
            string token = formula.substr(i, j - i);
            sum += isNumber(token) ? stoi(token) : cells[token];
            i = j + 1;
        }
        return sum;
    }
};

int main () {
    
    return 0;
}