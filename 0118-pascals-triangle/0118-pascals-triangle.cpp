class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> final;
        for(int i=0;i<numRows;i++){
            if(i==0){
                vector<int> vc;
                vc.push_back(1);
                final.push_back(vc);
            }
            else if(i==1){
                vector<int> vc;
                vc.push_back(1);
                vc.push_back(1);
                final.push_back(vc);
            }else{
                vector<int> pre=final[i-1];
                vector<int> vc;
                vc.push_back(1);
                for(int j=1;j<pre.size();j++){
                    vc.push_back(pre[j]+pre[j-1]);
                }
                vc.push_back(1);
                final.push_back(vc);
            }
        }
        return final;
    }
};