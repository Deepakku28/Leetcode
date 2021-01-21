class Solution {
public:
    int solution(int len1,int len2,int &m,int &n,string &ring,string &key,vector<int> mp[26],vector<vector<int>> &dp){
        if(len2==n){
            return 0;
        }
        if(dp[len1][len2]){
            return dp[len1][len2];
        }
        int ans=INT_MAX;
        for(int it:mp[key[len2]-'a']){
            int dist=abs(len1-it);
            ans=min(ans,min(dist,m-dist)+solution(it,len2+1,m,n,ring,key,mp,dp));
        }
        return dp[len1][len2]=ans+1;
    }
    
    int findRotateSteps(string ring, string key) {
        int m=ring.size();
        int n=key.size();
        vector<int> mp[26];
        for(int i=0;i<m;i++){
            mp[ring[i]-'a'].push_back(i);
        }
        vector<vector<int>> dp(m,vector<int>(n));
        return solution(0,0,m,n,ring,key,mp,dp);
    }
};
