class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        double ans=INT_MIN;
        double count=0;
        if(nums.size()==1 && k==1){
            return nums[0];
        }
        while(r<nums.size()){
            count+=nums[r];
            if((r-l+1)==k){
                ans=max(ans,count/k);
                count-=nums[l];
                l++;
            }
            // ans=max(ans,count/k);
            r++;
        }
        return ans;
    }
};