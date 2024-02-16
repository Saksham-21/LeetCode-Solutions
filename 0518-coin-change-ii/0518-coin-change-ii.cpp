class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long>> dp(n,vector<long> (amount+1,0));
        for(int i=0;i<=amount;i++){
            dp[0][i]=(i%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long not_take=dp[i-1][j];
                long take=0;
                if(coins[i]<=j) take=dp[i][j-coins[i]];
                dp[i][j]=take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};