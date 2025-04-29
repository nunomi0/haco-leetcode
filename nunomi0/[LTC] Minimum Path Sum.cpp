class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        // init
        int dp[210][210];
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                dp[i][j]=999999999;
            }
        }

        // bottom-up DP
        dp[0][0]=grid[0][0];
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                if (i+1!=grid.size()) dp[i+1][j]=min(dp[i+1][j],dp[i][j]+grid[i+1][j]);
                if (j+1!=grid[0].size()) dp[i][j+1]=min(dp[i][j+1],dp[i][j]+grid[i][j+1]);
            }
        }

        // debugging
        /*
        for (int i = 0; i<grid.size(); i++){
            for (int j = 0; j<grid[0].size(); j++){
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        */

        return dp[grid.size()-1][grid[0].size()-1];
    }
};
