class Solution {
public:
    int solution(string word1,string word2,int len1,int len2){
        int dp[len1+1][len2+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=len2;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=len1;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[len1][len2];
    }
    
    int minDistance(string word1, string word2) {
        int len1=word1.length();
        int len2=word2.length();
        return solution(word1,word2,len1,len2);
    }
};