class Solution {
public:
    bool isMagicSquare(int &x,int &y,vector<vector<int>>& grid){
        if(grid[x+1][y+1]!=5){
            return false;
        }
        vector<bool> used(10,false);
        for(int i=x;i<=x+2;i++){
            for(int j=y;j<=y+2;j++){
                int val=grid[i][j];
                if(val<1 || val>9 || used[val]==true){
                    return false;
                }
                used[val]=true;
            }
        }
        for(int i=x;i<=x+2;i++){
            int sum=0;
            for(int j=y;j<=y+2;j++){
                sum+=grid[i][j];
            }
            if(sum!=15){
                return false;
            }
        }
        for(int i=y;i<=y+2;i++){
            int sum=0;
            for(int j=x;j<=x+2;j++){
                sum+=grid[j][i];
            }
            if(sum!=15){
                return false;
            }
        }
        if(grid[x][y]+grid[x+1][y+1]+grid[x+2][y+2]!=15){
            return false;
        }
        if(grid[x][y+2]+grid[x+1][y+1]+grid[x+2][y]!=15){
            return false;
        }
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m<3 || n<3){
            return 0;
        }
        int ans=0;
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(isMagicSquare(i,j,grid)==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};
