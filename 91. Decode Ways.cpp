class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0'){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]=='0'){
            dp[1]=0;
        }
        else{
            dp[1]=1;
        }
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]=dp[i-1];
            }
            int twoDigit=stoi(s.substr(i-2,2));
            if(twoDigit<=26 && twoDigit>=10){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
