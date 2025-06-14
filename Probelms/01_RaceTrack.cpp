#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

struct Result {
    int output1[10000];
    Result() { memset(output1, -1, sizeof(output1)); }
};

struct State {
    int city;
    double time;
    vector<int> path;
    int boost, slow;

    bool operator>(const State &other) const {
        return time > other.time;
    }
};

Result needForSpeed(int input1, char input2[], int input3, int input4[]) {
    Result res;

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < input3 * 2; i += 2) {
        int u = input4[i];
        int v = input4[i + 1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0.0, {0}, 0, 0});

    double visited[1000][3][3];
    for (int i = 0; i < 1000; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                visited[i][j][k] = DBL_MAX;

    while (!pq.empty()) {
        State curr = pq.top(); pq.pop();
        int city = curr.city;
        double time = curr.time;
        int boost = curr.boost, slow = curr.slow;
        vector<int> path = curr.path;

        if (city == input1 - 1) {
            for (int i = 0; i < path.size(); i++)
                res.output1[i] = path[i];
            return res;
        }

        if (input2[city] == 'P') continue;

        if (visited[city][boost][slow] <= time) continue;
        visited[city][boost][slow] = time;

        if (input2[city] == 'N') boost = 2;
        if (input2[city] == 'S') slow = 2;
        if (input2[city] == 'C') time += 1;

        for (int neighbor : graph[city]) {
            double nextTime = time;
            if (boost > 0) nextTime += 0.5;
            else if (slow > 0) nextTime += 2;
            else nextTime += 1;

            vector<int> nextPath = path;
            nextPath.push_back(neighbor);
            pq.push({neighbor, nextTime, nextPath, max(0, boost - 1), max(0, slow - 1)});
        }
    }

    res.output1[0] = -1;
    return res;
}

int main () {
    
    return 0;
}