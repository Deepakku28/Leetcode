class Solution {
public:
    const static bool compare(vector<int> a,vector<int> b){
        if(a[0]<b[0]){
            return true;
        }
        if(a[0]==b[0]){
            return (a[1]<b[1]);
        }
        return false;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0){
            return 0;
        }
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> dp(n,1);
        int maxLen=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(envelopes[i][1]>envelopes[j][1] && envelopes[i][0]>envelopes[j][0] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                maxLen=max(maxLen,dp[i]);
            }
        }
        return maxLen;
    }
};
