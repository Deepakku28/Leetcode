class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int no_of_row=obstacleGrid.size();
        int no_of_column=obstacleGrid[0].size();
        int dp[no_of_row][no_of_column];
        for(int i=0;i<no_of_row;i++){
            for(int j=0;j<no_of_column;j++){
                dp[i][j]=obstacleGrid[i][j];
            }
        }
        if(dp[0][0]==1){
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<no_of_row;i++){
            if(dp[i][0]==0 && dp[i-1][0]==1){
                dp[i][0]=1;
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int i=1;i<no_of_column;i++){
            if(dp[0][i]==0 && dp[0][i-1]==1){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<no_of_row;i++){
            for(int j=1;j<no_of_column;j++){
                if(dp[i][j]==0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[no_of_row-1][no_of_column-1];
    }
};
