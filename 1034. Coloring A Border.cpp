class Solution {
public:
    
    void dfs(vector<vector<int>> &grid,int r0,int c0,int &n,int &m,int &currColor){
        if(r0<0 || c0<0 || r0>=n || c0>=m || grid[r0][c0]!=currColor){
            return;
        }
        grid[r0][c0]=(-1*(currColor));
        dfs(grid,r0,c0+1,n,m,currColor);
        dfs(grid,r0+1,c0,n,m,currColor);
        dfs(grid,r0,c0-1,n,m,currColor);
        dfs(grid,r0-1,c0,n,m,currColor);
        if(r0>0 && c0>0 && r0<n-1 && c0<m-1 && abs(grid[r0][c0+1])==currColor && abs(grid[r0+1][c0])==currColor && abs(grid[r0][c0-1])==currColor && abs(grid[r0-1][c0])==currColor){
            grid[r0][c0]=currColor;
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        
        int n=grid.size();
        int m=grid[0].size();
        int currColor=grid[r0][c0];
        dfs(grid,r0,c0,n,m,currColor);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<0){
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};
