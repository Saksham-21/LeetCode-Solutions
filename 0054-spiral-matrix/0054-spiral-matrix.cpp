class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
                cout<<matrix[top][i]<<" ";
            }
            top++;
            for(int j=top;j<=bottom;j++){
                ans.push_back(matrix[j][right]);
                cout<<matrix[j][right]<<" ";
            }
            right--;
            if (top <= bottom) {
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;}
            if (left <= right) {
            for(int j=bottom;j>=top;j--){
                ans.push_back(matrix[j][left]);
                cout<<matrix[j][left]<<" ";
            }
            left++;
            }
        }
        return ans;
        
    }
};