// https://school.programmers.co.kr/learn/courses/30/lessons/42898

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void printMatrix(const vector<vector<int>>& routes) {
    for (int i = 0 ; i < routes.size(); i++) {
        for (int j = 0; j < routes[0].size(); j++) {
            cout << routes[i][j] << " ";
        }
        cout << endl;
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> routes(n, vector<int>(m, -1));
    
    for (const auto& indices : puddles) {
        routes[indices[1] - 1][indices[0] - 1] = 0;
    }
    
    int modular = 1000000007;
    routes[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && j == 0) || routes[i][j] == 0) {
                continue;
            }
            int above = (i == 0) ? 0 : (routes[i-1][j] % modular);
            int left = (j == 0) ? 0 : (routes[i][j-1] % modular);
            
            routes[i][j] = (above + left) % modular;
        }
    }
    return routes[n-1][m-1];
}
