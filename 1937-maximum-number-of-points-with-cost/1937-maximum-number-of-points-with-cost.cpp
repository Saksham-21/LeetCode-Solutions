class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        // vector<vector<long long>> dp(m,vector<long long> (n,0));
        vector<long long> dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=points[0][i];
        }
        for(int i=1;i<m;i++){
            vector<long long> left(n,0),right(n,0),newDp(n,0);
            
            left[0]=dp[0];
            for(int j=1;j<n;j++){
                left[j]=max(left[j-1]-1,dp[j]);
            }
            
            right[n-1]=dp[n-1];
            for(int j=n-2;j>=0;j--){
                right[j]=max(right[j+1]-1,dp[j]);
            }
            
            
            for(int j=0;j<n;j++){
                newDp[j]=points[i][j]+max(left[j],right[j]);
            }
            dp=newDp;
        }
        long long res=INT_MIN;
        for(int y=0;y<n;y++){
            res=max(res,dp[y]);
        }
        return res;
    }
};