class Solution {
public:
    bool ispossible(vector<int> &nums,int td,int mid){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int x=ceil((double)nums[i]/ (double)mid);
            // int x=nums[i]/mid;
            cnt+=x;
            if(td<cnt){
                return false;
            }
        }
        return cnt<=td;
    }
    int smallestDivisor(vector<int>& nums, int td) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,td,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        // int z= ceil((double)x/ (double)y);
        return ans;
    }
};