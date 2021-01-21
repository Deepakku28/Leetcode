class Solution {
public:
    int solution(int row,int col,vector<vector<int>>& dungeon,vector<vector<int>>& dp,int &m,int &n){
        if(row>=m || col>=n){
            return INT_MAX;
        }
        if(row==m-1 && col==n-1){
            return (dungeon[row][col]<0?1-dungeon[row][col]:1);
        }
        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }
        int ans=min(solution(row+1,col,dungeon,dp,m,n),solution(row,col+1,dungeon,dp,m,n))-dungeon[row][col];
        return dp[row][col]=ans<=0?1:ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        return solution(0,0,dungeon,dp,m,n);
    }
};
