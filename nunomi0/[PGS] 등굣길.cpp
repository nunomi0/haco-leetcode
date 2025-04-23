#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    
    int arr[110][110], dp[110][110];
    
    for (int i = 0; i<puddles.size(); i++) arr[puddles[i][1]][puddles[i][0]]=1;
    
    dp[1][1]=1;
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
            if (arr[i][j]) continue;
            if (i!=1) dp[i][j]+=dp[i-1][j];
            if (j!=1) dp[i][j]+=dp[i][j-1];
            dp[i][j]%=1000000007;
        }
    }
    return dp[n][m];
}
