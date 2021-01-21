class Solution {
public:
    
    bool memoization(string &s1, string &s2, string &s3,int len1,int len2,int len3,vector<vector<int>>& dp){
        if(len1==s1.length() && len2==s2.length() && len3==s3.length()){
            return true;
        }
        if(dp[len1][len2]!=-1){
            return dp[len1][len2];
        }
        bool ans=false;
        if(len1<s1.length() && len3<s3.length() && s1[len1]==s3[len3]){
            ans=ans||memoization(s1,s2,s3,len1+1,len2,len3+1,dp);
        }
        if(len2<s2.length() && len3<s3.length() && s2[len2]==s3[len3]){
            ans=ans||memoization(s1,s2,s3,len1,len2+1,len3+1,dp);
        }
        return dp[len1][len2]=ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.length()+s2.length())!=(s3.length())){
            return false;
        }
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return memoization(s1,s2,s3,0,0,0,dp);
    }
};
