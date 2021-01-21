class Solution {
public:
    double solution(vector<vector<vector<double>>> &dp,int &N,int K,int r,int c){
        if(r<0 || c<0 || r>=N || c>=N){
            return 0;
        }
        if(K==0){
            return 1;
        }
        if(dp[r][c][K]!=-1){
            return dp[r][c][K];
        }
        double ans=0;
        ans+=(solution(dp,N,K-1,r-2,c+1)+solution(dp,N,K-1,r-1,c+2)+
              solution(dp,N,K-1,r+1,c+2)+solution(dp,N,K-1,r+2,c+1)+
              solution(dp,N,K-1,r+2,c-1)+solution(dp,N,K-1,r+1,c-2)+
              solution(dp,N,K-1,r-1,c-2)+solution(dp,N,K-1,r-2,c-1));
        return dp[r][c][K]=ans/8;
    }
    
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N+1,vector<vector<double>>(N+1,vector<double>(K+1,-1)));
        return solution(dp,N,K,r,c);
    }
};
