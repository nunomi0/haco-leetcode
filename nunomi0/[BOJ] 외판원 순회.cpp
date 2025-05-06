#include <iostream>
using namespace std;

int n,w[20][20],dp[20][1<<16];

int dfs(int cur, int visited) {

    // 모든 장소를 방문한 경우 (111111...)
    if (visited==(1<<n)-1) {
        if (w[cur][0]==0) return 999999999; // 1로 돌아갈 수 없음
        else return w[cur][0]; // 1로 돌아감
    }

    // dp 기록 또는 초기화
    if (dp[cur][visited]!=0) return dp[cur][visited]; // dp 기록이 있는 경우
    else dp[cur][visited]=999999999; // 초기화

    for (int i = 0; i<n; i++) {
        if (w[cur][i]==0) continue; // 방문할 수 없는 경우
        if (visited & (1<<i)) continue; // 방문한 적 있는 경우
        dp[cur][visited]=min(dp[cur][visited],w[cur][i]+dfs(i,visited|1<<i)); // 재귀
    }
    return dp[cur][visited];
}

int main() {
    cin >> n;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    cout << dfs(0,1);
}
