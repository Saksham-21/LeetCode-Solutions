class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int p1=0;
        int p2=0;
        int p3=0;
        
        for(int i=1;i<n;i++){
            int twop=dp[p1]*2;
            int threep=dp[p2]*3;
            int fivep=dp[p3]*5;
            
            dp[i]=min(twop,min(threep,fivep));
            if(dp[i]==twop) p1++;
            if(dp[i]==threep) p2++;
            if(dp[i]==fivep) p3++;
        }
        return dp[n-1];
    }
};