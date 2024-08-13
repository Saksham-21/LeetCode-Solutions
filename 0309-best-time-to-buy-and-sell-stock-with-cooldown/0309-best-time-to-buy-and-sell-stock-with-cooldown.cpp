class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int ind=n-1;ind>=0;ind--){
            dp[ind][1]=max(-arr[ind]+dp[ind+1][0],dp[ind+1][1]);    
            dp[ind][0]=max(arr[ind]+dp[ind+2][1],dp[ind+1][0]);
        }
        return dp[0][1];
    }
};