class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int pt=0;
        int n=nums.size();
        for (int i=1;i<n && pt<2;i++){
            if(nums[i-1]>=nums[i]){
                pt++;
            }
            if(i>1 && nums[i-2]>=nums[i]){
                nums[i]=nums[i-1];
            }
        }
        return pt<2;
    }
};