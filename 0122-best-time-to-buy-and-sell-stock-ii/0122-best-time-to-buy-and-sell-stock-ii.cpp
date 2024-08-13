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
        vector<vector<int>> dp(arr.size(),vector<int> (2,-1));
        return f(0,1,arr,dp);
    }
};