class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& vc) {
        vector<vector<int>> ans;
        sort(vc.begin(),vc.end());
        for(int i=0;i<vc.size();i++){
            if(ans.empty() || vc[i][0]>ans.back()[1]){
                ans.push_back(vc[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],vc[i][1]);
            }    
        }
        return ans;
    }
};