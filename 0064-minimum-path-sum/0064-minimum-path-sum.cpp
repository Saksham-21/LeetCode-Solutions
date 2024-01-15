class Solution {
public:
    int f(vector<vector<int>> &grid, vector<vector<int>> &dp, int i, int j) {
        if (i == 0 && j == 0) return grid[0][0];
        if (i < 0 || j < 0) return INT_MAX;
        if (dp[i][j] != -1) return dp[i][j];
        int left = grid[i][j] + f(grid, dp, i, j - 1);
        int up = grid[i][j] + f(grid, dp, i - 1, j);
        return dp[i][j] = min(left, up);
    }

    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return f(grid, dp, m - 1, n - 1);
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    int up = grid[i][j] + ((i > 0) ? dp[i - 1][j] : 1e9);
                    int left = grid[i][j] + ((j > 0) ? dp[i][j - 1] : 1e9);

                    dp[i][j] = min(left, up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
