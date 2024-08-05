class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int subsets=(1<<n);
        vector<vector<int>> ans;
        for(int i=0;i<=subsets-1;i++){
            vector<int> mini;
            for(int j=0;j<=n-1;j++){
                if(i & (1<<j)){
                    mini.push_back(nums[j]);
                }
            }
            ans.push_back(mini);
        }
        return ans;
    }
};