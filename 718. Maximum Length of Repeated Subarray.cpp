class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1=A.size();
        int len2=B.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        //dp[0][0]=;
        int ans=0;
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
