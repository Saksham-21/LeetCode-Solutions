class Solution {
public:
    int f(string &text1,string &text2,int i1,int i2,vector<vector<int>> &dp){
        if(i1<0 || i2<0){
            return 0;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(text1[i1]==text2[i2]){
            return dp[i1][i2]=1+f(text1,text2,i1-1,i2-1,dp);
        }
        return dp[i1][i2]=max(f(text1,text2,i1-1,i2,dp),f(text1,text2,i1,i2-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(text1,text2,n-1,m-1,dp);
    }
};