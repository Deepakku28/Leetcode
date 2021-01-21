class Solution {
public:
    int minAmount(int start,int end,vector<vector<int>> &dp){
        if(start>=end){
            return 0;
        }
        if(dp[start][end]!=INT_MAX){
            return dp[start][end];
        }
        for(int i=start;i<=end;i++){
            dp[start][end]=min(dp[start][end],i+max(minAmount(i+1,end,dp),minAmount(start,i-1,dp)));
        }
        return dp[start][end];
    }
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        return minAmount(1,n,dp);
    }
};
