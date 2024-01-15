class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int> (triangle[m-1].size(),0));
        for(int i=0;i<m;i++){
            int x=triangle[i].size();
            for(int j=0;j<x;j++){
                if(i==0 && j==0) {
                    dp[i][j]=triangle[i][j];
                    cout<<"DP"<<i<<j<<"   "<<dp[i][j]<<endl;
                }
                else{
                    int up=triangle[i][j]+((i!=j)?dp[i-1][j]:1e9);
                    int dia=triangle[i][j]+((j!=0)?dp[i-1][j-1]:1e9);
                    cout<<"UP--"<<up<<" "<<"DIA--"<<dia<<endl;
                
                
                    dp[i][j]=min(up,dia);
                    cout<<"\n";
                    cout<<"DP"<<i<<j<<"   "<<dp[i][j]<<endl;   
                }
                 
            }
        }
        for(int i=0;i<m;i++){
            cout<<dp[m-1][i]<<" ";
        }
        int minTotal = INT_MAX;
        for (int i = 0; i < m; i++) {
            minTotal = std::min(minTotal, dp[m-1][i]);
        }
        return minTotal;
    }
};