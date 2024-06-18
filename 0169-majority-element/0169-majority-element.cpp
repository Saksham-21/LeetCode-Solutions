class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int val;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                val=nums[i];
            }else if(nums[i]==val){
                cnt++;
            }else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val) cnt1++;
        }
        if(cnt1>(nums.size()/2)){
            return val;
        }
        return -1;
    }
};