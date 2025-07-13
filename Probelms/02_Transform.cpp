#include <iostream>
#include <vector>
#include <string>
using namespace std;

char nextChar(char c) {
    return c == 'z' ? 'a' : c + 1;
}

bool isSimilar(string& oldPass, string& newPass) {
    int i = 0;
    int j = 0; 

    while (i < oldPass.length() && j < newPass.length()) {
        char original = newPass[j];
        char cycled = nextChar(original);

        if (oldPass[i] == original || oldPass[i] == cycled) {
            i++;
        }
        j++;
    }

    return i == oldPass.length();
}

vector<string> solve(vector<string> oldpass, vector<string> newpass) {
    int n = oldpass.size();
    vector<string> res;

    for (int i = 0; i < n; i++) {
        if (isSimilar(oldpass[i], newpass[i])) {
            res.push_back("YES");
        } else {
            res.push_back("NO");
        }
    }
    return res;
}

int main() {  

    vector<string> newpass = {"baacbab", "accdb", "baacba"};
    vector<string> oldpass = {"abdbc", "ach", "abb"};

    vector<string> result = solve(oldpass, newpass);
    for (const string& res : result) {
        cout << res << endl;    
    }
    return 0;
}
