class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> dp(N,vector<int>(N,1));
        for(vector<int> it:mines){
            dp[it[0]][it[1]]=0;
        }
        vector<vector<int>> left(N,vector<int>(N,0));
        vector<vector<int>> right(N,vector<int>(N,0));
        vector<vector<int>> up(N,vector<int>(N,0));
        vector<vector<int>> down(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dp[i][j]==1){ 
                    up[i][j]=((i-1>=0)?up[i-1][j]+1:1);
                    left[i][j]=((j-1>=0)?left[i][j-1]+1:1);
                }
                else{
                    left[i][j]=0;
                    up[i][j]=0;
                }
            }    
        }
        
        for(int i=N-1;i>=0;i--){
            for(int j=N-1;j>=0;j--){
                if(dp[i][j]==1){ 
                    down[i][j]=((i+1<N)?down[i+1][j]+1:1);
                    right[i][j]=((j+1<N)?right[i][j+1]+1:1);
                }
                else{
                    down[i][j]=0;
                    right[i][j]=0;
                }
            }    
        }
        
        int maxOrder=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                maxOrder=max(maxOrder,min({left[i][j],right[i][j],up[i][j],down[i][j]}));
            }
        }
        return maxOrder;
    }
};
