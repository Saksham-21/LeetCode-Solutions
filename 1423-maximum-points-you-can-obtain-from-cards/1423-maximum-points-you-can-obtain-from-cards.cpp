class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lsum=0,rsum=0,max_sum=0;
        for(int i=0;i<k;i++){
            lsum+=nums[i];
        }
        max_sum=lsum;
        int rindex=nums.size()-1;
        for(int i=k-1;i>=0;i--){
            lsum-=nums[i];
            rsum+=nums[rindex];
            rindex--;
            
            max_sum=max(max_sum,(lsum+rsum));
        }
        return max_sum;
    }
};