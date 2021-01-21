class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int mod=1000000007;
        int n=S.length();
    
        vector<int> prev(n,-1);
        unordered_map<char,int> mpPrev;
        for(int i=0;i<n;i++){
            if(mpPrev.find(S[i])!=mpPrev.end()){
                prev[i]=mpPrev[S[i]];
            }
            mpPrev[S[i]]=i;
        }

        vector<int> next(n,n);
        unordered_map<char,int> mpNext;
        for(int i=n-1;i>=0;i--){
            if(mpNext.find(S[i])!=mpNext.end()){
                next[i]=mpNext[S[i]];
            }
            mpNext[S[i]]=i;
        }

        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;i<n && j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    dp[i][j]=2;
                }
                else{
                    if(S[i]!=S[j]){
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    }
                    else{
                        int nextIndex=next[i];
                        int prevIndex=prev[j];

                        if(nextIndex>prevIndex){
                            dp[i][j]=(2*dp[i+1][j-1]+2)%mod;
                        }
                        else if(nextIndex==prevIndex){
                            dp[i][j]=(2*dp[i+1][j-1]+1)%mod;
                        }
                        else{
                            dp[i][j]=(2*dp[i+1][j-1]-dp[nextIndex+1][prevIndex-1])%mod;
                        }
                    }
                }
                dp[i][j]=(dp[i][j]<0?dp[i][j]+mod:dp[i][j])%mod;
            }
        }
        return (dp[0][n-1])%mod;
    }
};
