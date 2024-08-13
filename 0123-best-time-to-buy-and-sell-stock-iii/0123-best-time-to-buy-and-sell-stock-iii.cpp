class Solution {
public:
    int maxProfit(vector<int>& arr) {
        vector<vector<int>> pre(2,vector<int> (3,0));
        vector<vector<int>> curr(2,vector<int> (3,0));
        int n=arr.size();
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        curr[buy][cap]=max(-arr[ind]+ pre[0][cap],0+pre[1][cap]);
                    }else{
                        curr[buy][cap]=max(arr[ind]+pre[1][cap-1],0+pre[0][cap]);
                    }
                    
                }
            }
            pre=curr;
        }
        return pre[1][2];
    }
};