class Solution {
public:
    void dfs(vector<vector<int>>& grid,int &row,int &col,int i,int j){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==1){
            return;
        }
        grid[i][j]=1;
        dfs(grid,row,col,i,j+1);
        dfs(grid,row,col,i+1,j);
        dfs(grid,row,col,i,j-1);
        dfs(grid,row,col,i-1,j);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<col;i++){
            if(grid[0][i]==0){
                dfs(grid,row,col,0,i);
            }
            if(grid[row-1][i]==0){
                dfs(grid,row,col,row-1,i);
            }
        }
        for(int i=0;i<row;i++){
            if(grid[i][0]==0){
                dfs(grid,row,col,i,0);
            }
            if(grid[i][col-1]==0){
                dfs(grid,row,col,i,col-1);
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    dfs(grid,row,col,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
