class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto it:wordDict){
            mp[it]=1;
        }
        vector<bool> dp(s.length()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                string str=s.substr(j,i-j);
                if((mp[str]>=1)&&(dp[j]==true)){
                    dp[i]=true;
                }
            }
        }
        return dp[s.length()];
    }
};
