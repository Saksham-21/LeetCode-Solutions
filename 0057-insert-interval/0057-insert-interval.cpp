class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& nnums) {
        vector<vector<int>> ans;
        int i=0;
        while(i<nums.size()){
            if(nums[i][1]<nnums[0]){
                ans.push_back(nums[i]);
            }else if(nums[i][0]>nnums[1]){
                break;
            }else{
                nnums[0]=min(nums[i][0],nnums[0]);
                nnums[1]=max(nums[i][1],nnums[1]);
                
            }
            i++;
        }
        ans.push_back(nnums);
        while(i<nums.size()){
            ans.push_back(nums[i]);
            i++;
        }
        return ans;
    }
};