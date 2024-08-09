class Solution {
public:
    bool check(vector<vector<int>>& grid,int i,int j){
        set<int> s({1,2,3,4,5,6,7,8,9});
        for(int x=0;x<3;x++){
            for(int y=0;y<3;y++){
                s.erase(grid[x+i][y+j]);
            }
        }
        if(!s.empty()){
            return false;
        }
        
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];

        // Check rows
        if (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] != sum) return false;
        if (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] != sum) return false;

        // Check columns
        if (grid[i][j] + grid[i+1][j] + grid[i+2][j] != sum) return false;
        if (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] != sum) return false;
        if (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] != sum) return false;

        // Check diagonals
        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != sum) return false;
        if (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != sum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int cnt=0;
        for(int i=0;i<=r-3;i++){
            for(int j=0;j<=c-3;j++){
                if(check(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};