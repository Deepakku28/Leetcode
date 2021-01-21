class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int &row,int &col){
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]=='0'){
            return ;
        }
        grid[r][c]='0';
        dfs(grid,r,c+1,row,col);
        dfs(grid,r+1,c,row,col);
        dfs(grid,r,c-1,row,col);
        dfs(grid,r-1,c,row,col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if(row==0){
            return 0;
        }
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,row,col);
                }
            }
        }
        return ans;
    }
};
