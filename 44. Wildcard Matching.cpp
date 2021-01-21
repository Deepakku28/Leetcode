class Solution {
public:
    bool isMatch(string s, string p) {
        int row=s.length();
        int col=p.length();
        vector<vector<bool>> dp(row+1,vector<bool>(col+1,false));

        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0 && j>0 && p[j-1]=='*'){
                    dp[0][j]=dp[0][j-1];
                }
                else if((i>0 && j>0 && s[i-1]==p[j-1])||(i>0 && j>0 && p[j-1]=='?')){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(i>0 && j>0 && p[j-1]=='*'){
                    dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
                }
            }
        }
        return dp[row][col];
    }
};
