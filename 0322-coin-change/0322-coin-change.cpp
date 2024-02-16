class Solution {
public:
    int cal(int i,int A,vector<int> coin,vector<vector<int>> &dp){
        if(i==0){
            if(A%coin[0]==0){
                return A/coin[0];
            }else{
                return 1e9;
            }
        }
        if(dp[i][A]!= -1) return dp[i][A];
        int not_take=0+cal(i-1,A,coin,dp);
        int take=INT_MAX;
        if(coin[i]<=A){
            take=1+cal(i,A-coin[i],coin,dp); 
        }
        return dp[i][A]= min(take,not_take);
    }
    // int coinChange(vector<int>& coins, int amount) {
    //     vector<vector<int>> dp(coins.size(),vector<int> (amount+1,0));
    //     for(int j=0;j<=amount;j++){
    //         if(j%coins[0]==0){
    //             dp[0][j]=j/coins[0];
    //         }else{
    //             dp[0][j]=1e9;
    //         }
    //     }
    //     for(int i=1;i<coins.size();i++){
    //         for(int j=0;j<=amount;j++){
    //             int not_take=dp[i-1][j];
    //             int take=1e9;
    //             if(coins[i]<=j){
    //                 take=1+dp[i][j-coins[i]]; 
    //             }
    //             dp[i][j]= min(take,not_take);
    //         }
    //     }
    //     int ans=dp[coins.size()-1][amount];
    //     return ans==1e9 ? -1:ans;
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> pre(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0){
                pre[j]=j/coins[0];
            }else{
                pre[j]=1e9;
            }
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int not_take=pre[j];
                int take=1e9;
                if(coins[i]<=j){
                    take=1+curr[j-coins[i]]; 
                }
                curr[j]= min(take,not_take);
            }
            pre=curr;
        }
        int ans=pre[amount];
        return ans==1e9 ? -1:ans;
    }
};