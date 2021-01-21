class Solution {
public:
    int solution(int r1,int c1,int c2,int &n,vector<vector<vector<int>>> &dp,vector<vector<int>>& grid){
        int r2=r1+c1-c2;
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1){
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1){
            return dp[r1][c1][c2];
        }
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        int ans=grid[r1][c1];
        if(c1!=c2){
            ans+=grid[r2][c2];
        }
        ans+=max({solution(r1+1,c1,c2,n,dp,grid),solution(r1,c1+1,c2+1,n,dp,grid),solution(r1+1,c1,c2+1,n,dp,grid),solution(r1,c1+1,c2,n,dp,grid)});
        return dp[r1][c1][c2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        return max(0,solution(0,0,0,n,dp,grid));
    }
};
