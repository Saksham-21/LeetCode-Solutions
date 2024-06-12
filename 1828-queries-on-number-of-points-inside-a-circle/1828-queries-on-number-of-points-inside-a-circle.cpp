class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int temp=0;
            for(int j=0;j<points.size();j++){
                int dx = points[j][0] - queries[i][0];
                int dy = points[j][1] - queries[i][1];
                int r=queries[i][2];
                if(dx*dx + dy*dy <= r*r){
                    temp++;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};