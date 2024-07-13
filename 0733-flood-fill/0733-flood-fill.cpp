class Solution {
public:
    void recursion(vector<vector<int>>& image,int sr,int sc,int color,int m,int n,int source){
        if(sr<0 || sr>=m || sc<0 || sc>=n){
            return ;
        }else if(image[sr][sc]!=source){
            return;
        }
        image[sr][sc]=color;
        
        recursion(image,sr+1,sc,color,m,n,source);
        recursion(image,sr-1,sc,color,m,n,source);
        recursion(image,sr,sc+1,color,m,n,source);
        recursion(image,sr,sc-1,color,m,n,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }else{
            int m=image.size();
            int n=image[0].size();
            int source=image[sr][sc];
            recursion(image,sr,sc,color,m,n,source);
            return image;
        }
    }
};