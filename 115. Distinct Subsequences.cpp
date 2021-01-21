class Solution {
public:
    
    int memoization(string &s, string &t,int len1,int len2,vector<vector<int>> &dp){
        if(len2==t.length()){
            return 1;
        }
        if(len1==s.length()){
            return 0;
        }
        if(dp[len1][len2]!=-1){
            return dp[len1][len2];
        }
        int ans=0;
        if(s[len1]==t[len2] && len1<s.length() && len2<t.length()){
            ans+=(memoization(s,t,len1+1,len2,dp)+memoization(s,t,len1+1,len2+1,dp));
        }
        if(s[len1]!=t[len2] && len1<s.length() && len2<t.length()){
            ans+=memoization(s,t,len1+1,len2,dp);
        }
        return dp[len1][len2]=ans;
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        return memoization(s,t,0,0,dp);
    }
};
