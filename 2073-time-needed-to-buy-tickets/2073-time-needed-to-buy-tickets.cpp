class Solution {
public:
    int timeRequiredToBuy(vector<int>& nums, int k) {
        int t=0;
        int n=nums.size();
        while(nums[k]>0){
            if(nums[k]==0){
                break;
            }
            for(int i=0;i<n;i++){
                if(nums[i]>0){
                    nums[i]--;
                    t++;
                    if(i==k && nums[k]==0){
                        break;
                    }
                }
            }
        }
        return t;
    }
};