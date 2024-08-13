class Solution {
public:
    int f(int ind,int buy,vector<int> &arr,vector<vector<int>> &dp){
        if(ind==arr.size()) return 0;
        int profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            profit=(max(-arr[ind]+f(ind+1,0,arr,dp),0+f(ind+1,1,arr,dp)));
        }else{
            profit=(max(arr[ind]+f(ind+1,1,arr,dp),0+f(ind+1,0,arr,dp)));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(2,0);
        vector<int> curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=(max(-arr[ind]+dp[0],0+dp[1]));
                }else{
                    profit=(max(arr[ind]+dp[1],0+dp[0]));
                }
                curr[buy]=profit;
            }
            dp=curr;
        }
        return dp[1];
    }
};