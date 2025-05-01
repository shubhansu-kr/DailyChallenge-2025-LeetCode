// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/?envType=daily-question&envId=2025-05-01

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
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size());

        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

private:
    bool canAssign(const vector<int>& tasks, const vector<int>& workers,
                    int pills, int strength, int taskCount) {
        deque<int> boosted;
        int w = workers.size() - 1;
        int freePills = pills;

        for (int t = taskCount - 1; t >= 0; --t) {
            int task = tasks[t];

            if (!boosted.empty() && boosted.front() >= task) {
                boosted.pop_front();
            } else if (w >= 0 && workers[w] >= task) {
                --w;
            } else {
                while (w >= 0 && workers[w] + strength >= task) {
                    boosted.push_back(workers[w--]);
                }
                if (boosted.empty() || freePills == 0) {
                    return false;
                }
                boosted.pop_back();
                --freePills;
            }
        }

        return true;
    }
};

int main () {
    
    return 0;
}