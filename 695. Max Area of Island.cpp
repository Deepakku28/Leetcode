class Solution {
public:
    
    int dfs(int i,int j,int &m,int &n,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int curr=1;
        return curr+=dfs(i,j+1,m,n,grid)+dfs(i+1,j,m,n,grid)+dfs(i,j-1,m,n,grid)+dfs(i-1,j,m,n,grid);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0){
            return 0;
        }
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,dfs(i,j,m,n,grid));
                }
            }
        }
        return maxArea;
    }
};
