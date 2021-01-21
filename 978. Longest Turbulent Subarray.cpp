class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n=A.size();
        vector<vector<int>> dp(2,vector<int>(n,1));
        for(int i=1;i<n;i++){
            if(A[i-1]<A[i])
                dp[0][i]=1+dp[1][i-1];
            else if(A[i-1]>A[i])
                dp[1][i]=1+dp[0][i-1];
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max({ans,dp[0][i],dp[1][i]});
        }
        return ans;
    }
};
