class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,0);
        if(n==0){
            return 1;
        }
        if(n==1){
            return 10;
        }
        dp[0]=1;
        dp[1]=9;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]*(10-i+1));
        }
        int ans=0;
        for(auto it:dp){
            ans+=it;
        }
        return ans;
    }
};
