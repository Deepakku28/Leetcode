class Solution {
public:
    void helper(vector<vector<int>>& grid,int &m,int &n,int x,int y,int &endX,int &endY,int &ans,int steps){
        if(x<0 || x>=m || y<0 || y>=n || grid[x][y]==-1){
            return;
        }
        if(x==endX && y==endY && steps==-1){
            ans++;
            return;
        }
        grid[x][y]=-1;
        helper(grid,m,n,x,y+1,endX,endY,ans,steps-1);
        helper(grid,m,n,x+1,y,endX,endY,ans,steps-1);
        helper(grid,m,n,x,y-1,endX,endY,ans,steps-1);
        helper(grid,m,n,x-1,y,endX,endY,ans,steps-1);
        grid[x][y]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int startX=-1;
        int startY=-1;
        int endX=-1;
        int endY=-1;
        int steps=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
                if(grid[i][j]==2){
                    endX=i;
                    endY=j;
                }
                if(grid[i][j]==0){
                    steps++;
                }
            }
        }
        int ans=0;
        helper(grid,m,n,startX,startY,endX,endY,ans,steps);
        return ans;
    }
};
