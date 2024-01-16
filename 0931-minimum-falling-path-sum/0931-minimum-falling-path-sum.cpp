class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
            // cout<<dp[0][i]<<endl;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                // cout<<"UP---"<<up<<" ";
                int dia_left=matrix[i][j]+((j!=0)?dp[i-1][j-1]:1e9);
                // cout<<"DL---"<<dia_left<<" ";
                int dia_right=matrix[i][j]+((j!=(n-1))?dp[i-1][j+1]:1e9);
                // cout<<"DR---"<<dia_right<<endl;
                dp[i][j]=min(up,min(dia_left,dia_right));
                // cout<<"DP"<<i<<j<<dp[i][j]<<endl;
                // cout<<"\n";
            }
        }
        int minTerm=INT_MAX;
        for(int i=0;i<n;i++){
            minTerm=min(dp[n-1][i],minTerm);
        }
        return minTerm;
    }
};