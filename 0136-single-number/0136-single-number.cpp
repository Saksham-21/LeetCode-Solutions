class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        // unordered_map<int,int> mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }
        // for(auto p:mp){
        //     if(p.second==1){
        //         return p.first;
        //     }
        // }
        // return -1;
        
        
        int result=0;
        for(int i=0;i<n;i++){
            result^=nums[i];
        }
        return result;
    }
};