class Solution {
public:
    int mod=1000000007;
    int solution(vector<vector<vector<int>>> &dp,int &m,int &n,int currRow,int currCol,int maxDist){
        if(currRow<0 || currCol<0 || currRow>=m || currCol>=n){
            return 1;
        }
        if(maxDist<=0){
            return 0;
        }
        if(dp[currRow][currCol][maxDist]!=-1){
            return dp[currRow][currCol][maxDist];
        }
        int ans=0;
        ans=(ans+solution(dp,m,n,currRow,currCol+1,maxDist-1))%mod;
        ans=(ans+solution(dp,m,n,currRow+1,currCol,maxDist-1))%mod;
        ans=(ans+solution(dp,m,n,currRow,currCol-1,maxDist-1))%mod;
        ans=(ans+solution(dp,m,n,currRow-1,currCol,maxDist-1))%mod;
        return dp[currRow][currCol][maxDist]=ans;
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(50,vector<vector<int>>(50,vector<int>(51,-1)));
        return solution(dp,m,n,i,j,N);
    }
};
