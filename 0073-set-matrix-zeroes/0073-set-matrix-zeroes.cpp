class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        set<int> row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);    
                }
            }
        }
        for(auto x:row){
            for(int j=0;j<n;j++){
                matrix[x][j]=0;
            }
        }
        // cout<<endl;
        for(auto x:col){
            for(int i=0;i<m;i++){
                matrix[i][x]=0;
            }
        }
        // cout<<endl;
    }
};