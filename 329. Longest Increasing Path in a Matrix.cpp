class Solution {
public:
    
    int dfs(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &matrix,int &m,int &n,int val){
        if(i<0 || i>=m || j<0 || j>=n || matrix[i][j]<=val){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        
        return dp[i][j]=max({dfs(i,j+1,dp,matrix,m,n,matrix[i][j]),dfs(i+1,j,dp,matrix,m,n,matrix[i][j]),dfs(i,j-1,dp,matrix,m,n,matrix[i][j]),dfs(i-1,j,dp,matrix,m,n,matrix[i][j])})+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxLen=0;
        int m=matrix.size();
        if(m==0){
            return maxLen;
        }
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==0){
                    dfs(i,j,dp,matrix,m,n,INT_MIN);
                    maxLen=max(maxLen,dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};
