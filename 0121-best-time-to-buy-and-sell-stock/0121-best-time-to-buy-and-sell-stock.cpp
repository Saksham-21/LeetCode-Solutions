class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if(arr.size()<=1){
            return 0;
        }
        int mini=arr[0];
        int profit=0;
        for(int i=0;i<arr.size();i++){
            if(mini>arr[i]){
                mini=arr[i];
            }else{
                profit=max(profit,arr[i]-mini);
            }
        }
        return profit;
    }
};