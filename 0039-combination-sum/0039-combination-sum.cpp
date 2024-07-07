class Solution {
public:
    void recursion(int ind,int tar,vector<int> candi,vector<int>& vec,vector<vector<int>>& fvc){
        if(candi.size()==ind){
            return ;
        }
        if(tar==0){
            fvc.push_back(vec);
            return ;
        }
        // if(candi.size()==ind){
        //     if(tar==0){
        //         fvc.push_back(vec);
        //     }
        //     return ;
        // }
        
        if(candi[ind]<=tar){
            vec.push_back(candi[ind]);
            recursion(ind,tar-candi[ind],candi,vec,fvc);
            vec.pop_back();
        }
        recursion(ind+1,tar,candi,vec,fvc);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> fvc;
        vector<int> vc;
        recursion(0,target,candidates,vc,fvc);
        return fvc;
    }
};