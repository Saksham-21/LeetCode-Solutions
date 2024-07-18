class Solution {
public:
    int cal(vector<int>& nums, int k){
        int l=0,r=0,cnt=0;
        int count_odd=0;
        for(;r<nums.size();r++){
           if(nums[r]%2!=0){
               count_odd++;
           }
           for(;count_odd>k;l++){
               if(nums[l]%2!=0){
                   count_odd--;
               }
           }
           cnt+=(r-l+1); 
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return cal(nums,k)-cal(nums,k-1);
    }
};