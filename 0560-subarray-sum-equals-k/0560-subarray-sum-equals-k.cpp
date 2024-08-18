class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map <int,int>mpp;
        int preSum=0,cnt=0;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            int re=preSum-k;
            cnt+=mpp[re];
            
            mpp[preSum]+=1;
        }
        return cnt;
    }
};