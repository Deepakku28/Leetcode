class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int no_of_row=grid.size();
        int no_of_column=grid[0].size();
        if(no_of_row==0 || no_of_column==0){
            return 0;
        }
        for(int i=1;i<no_of_column;i++){
            grid[0][i]=grid[0][i]+grid[0][i-1];
        }
        for(int i=1;i<no_of_row;i++){
            grid[i][0]=grid[i][0]+grid[i-1][0];
        }
        for(int i=1;i<no_of_row;i++){
            for(int j=1;j<no_of_column;j++){
                grid[i][j]=grid[i][j]+min(grid[i][j-1],grid[i-1][j]);
            }
        }
        return grid[no_of_row-1][no_of_column-1];
    }
};
