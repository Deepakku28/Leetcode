class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        if(n<=2){
            return n;
        }
        int ans=2;
        vector<vector<int>> dp(n,vector<int>(n+1001,0));
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int diff=A[j]-A[i]+501;
                dp[j][diff]=max(2,dp[i][diff]+1);
                ans=max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};
