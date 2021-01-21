class Solution {
public:
    int numSquares(int n) {
        int len=sqrt(n);
        vector<int> perfectSq(len);
        for(int i=0;i<len;i++){
            perfectSq[i]=((i+1)*(i+1));
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=len-1;j>=0;j--){
                if(perfectSq[j]<=i){
                    dp[i]=min(dp[i],dp[i-perfectSq[j]]+1);
                }
            }
        }
        return dp[n];
    }
};
