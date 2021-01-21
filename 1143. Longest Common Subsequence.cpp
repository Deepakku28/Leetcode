class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.length()+1,vector<int>(text1.length()+1,0));
        for(int i=1;i<=text2.length();i++){
            for(int j=1;j<=text1.length();j++){
                if(text2[i-1]==text1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text2.length()][text1.length()];
    }
};
