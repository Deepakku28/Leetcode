class Solution {
public:
    int distinctSubseqII(string S) {
        int mod=(1e9+7);
        int n=S.size();
        vector<int> pos(26,-1);
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=2*dp[i-1]%mod;
            int index=S[i-1]-'a';
            if(pos[index]!=-1){
                dp[i]=(dp[i]-dp[pos[index]-1])%mod;
            }
            pos[index]=i;
        }
        if(dp[n]-1<0){
            return (mod+dp[n]-1);
        }
        return dp[n]-1;
    }
};
