class Solution {
public:
    int minSteps(int n) {
        if(n<2){
            return 0;
        }
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++){
            dp[i]=i;
            for(int j=i;j>1;j--){
                if(i%j==0){
                    dp[i]=min(dp[i],dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};
