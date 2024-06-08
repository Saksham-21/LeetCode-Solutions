class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true;
        bool dec=true;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                dec=false;
            }else if(nums[i-1]>nums[i]){
                inc=false;
            }
        }
        return inc || dec;
    }
};