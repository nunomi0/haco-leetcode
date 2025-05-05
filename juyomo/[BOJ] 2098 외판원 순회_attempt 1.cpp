// Author: Juyoung Moon
// https://www.acmicpc.net/problem/2098
// Attempted: May 5, 2025
// 백트래킹 사용, 시간초과

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void backtrack(const vector<vector<int>>& cost,
               int lastVisited, int numVisited, vector<bool>& visited, int currCost,
               int& minCost) {
    if (numVisited == cost.size()) {
        currCost += cost[lastVisited][0];
        if (currCost < minCost) {
            minCost = currCost;
        }
        return;
    }

    for (int i = 0; i < visited.size(); i++) {
        int newCost = cost[lastVisited][i];
        if (!visited[i] && newCost != 0) {
            visited[i] = true;
            backtrack(cost,
                      i, numVisited + 1, visited, currCost + newCost,
                      minCost);
            visited[i] = false;
        }
    }
}

int main() {
    int numCity = 4;
    cin >> numCity;
    
    vector<vector<int>> cost(numCity, vector<int>(numCity));

    for (int r = 0; r < numCity; r++) {
        for (int c = 0; c < numCity; c++) {
            int tmp; 
            cin >> tmp;
            cost[r][c] = tmp;
        }
    }

    vector<bool> visited(numCity, false);
    visited[0] = true;
    int minCost = INT_MAX;
    backtrack(cost,
              0, 1, visited, 0,
              minCost);

   cout << minCost << endl;
}
