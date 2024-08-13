class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        vector<int> pre(2,0);
        vector<int> curr(2,0);
        int n=arr.size();
        for(int ind=n-1;ind>=0;ind--){
            curr[1]=max(-arr[ind]+pre[0],pre[1]);
            curr[0]=max(arr[ind]-fee+pre[1],pre[0]);
            pre=curr;
        }
        return pre[1];
    }
};