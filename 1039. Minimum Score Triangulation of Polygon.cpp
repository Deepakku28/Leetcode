class Solution {
public:
    int minScoreTriangulation(vector<int>& val) {
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n && i<n;i++,j++){
                if(gap==0 || gap==1){
                    dp[i][j]=0;
                }
                else if(gap==2){
                    dp[i][j]=val[i]*val[i+1]*val[i+2];
                }
                else{
                    int minVal=INT_MAX;
                    for(int k=i+1;k<j;k++){
                        int triangle=val[i]*val[k]*val[j];
                        int left=dp[i][k];
                        int right=dp[k][j];
                        int total=triangle+left+right;
                        minVal=min(minVal,total);
                    }
                    dp[i][j]=minVal;
                }
            }
        }
        return dp[0][n-1];
    }
};
