class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &newGrid,int &len){
        if(i<0 || i>=len || j<0 || j>=len || newGrid[i][j]==0){
            return ;
        }
        newGrid[i][j]=0;
        dfs(i,j+1,newGrid,len);
        dfs(i+1,j,newGrid,len);
        dfs(i,j-1,newGrid,len);
        dfs(i-1,j,newGrid,len);
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> newGrid(n*3,vector<int>(n*3,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    newGrid[i*3][j*3+2]=0;
                    newGrid[i*3+1][j*3+1]=0;
                    newGrid[i*3+2][j*3]=0;
                }
                else if(grid[i][j]=='\\'){
                    newGrid[i*3+2][j*3+2]=0;
                    newGrid[i*3+1][j*3+1]=0;
                    newGrid[i*3][j*3]=0;
                }
            }
        }
        int m=3*n;
        int ans=0;
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(newGrid[i][j]==1){
                    dfs(i,j,newGrid,m);
                    ans++;
                }
            }
        }
        return ans;
    }
};
