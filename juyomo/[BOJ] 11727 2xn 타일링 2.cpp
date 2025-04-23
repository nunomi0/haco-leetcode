// Author: Juyoung Moon
// https://www.acmicpc.net/problem/11727

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i < n; i++) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }
    cout << dp[n-1];
}