class Solution {
public:
    int f(vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid,int i,int j){
        if (i < 0 || j < 0) {
            return 0; // Out of bounds
        }
        if (obstacleGrid[i][j] == 1) {
            return 0; // Obstacle encountered
        }
        if (i == 0 && j == 0) {
            return 1; // Reached the starting point
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return the precomputed value
        }
        // Calculate the number of unique paths recursively
        return dp[i][j] = f(dp, obstacleGrid, i - 1, j) + f(dp, obstacleGrid, i, j - 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==1 && n==1) return obstacleGrid[m-1][n-1]==1?0:1;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(dp,obstacleGrid,m-1,n-1);
    }
};