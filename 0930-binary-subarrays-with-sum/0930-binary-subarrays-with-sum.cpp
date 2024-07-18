class Solution {
public:
    int calculate(vector<int>& nums,int goal){
        int l=0,r=0,ans=0;
        int sum=0;
        for(;r<nums.size();r++){
            sum+=nums[r];
            for(;sum>goal && l<=r;l++){
                sum-=nums[l];
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return calculate(nums,goal)-calculate(nums,goal-1);
    }
};