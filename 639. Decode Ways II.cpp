const int mod=1e9+7;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0'){
            return 0;
        }
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]=='*'){
            dp[1]=9;
        }
        else if(s[0]!='0'){
            dp[1]=1;
        }
        else{
            dp[1]=1;
        }
        for(int i=2;i<=n;i++){
            int first=s[i-2];
            int second=s[i-1];
            if(second>'0'){
                dp[i]=(dp[i]+dp[i-1])%mod;
            }
            else if(second=='*'){
                dp[i]=(dp[i]+9*dp[i-1])%mod;
            }
            if(first=='*'){
                if(second=='*'){
                    dp[i]=(dp[i]+dp[i-2]*15)%mod;
                }
                else if(second<='6'){
                    dp[i]=(dp[i]+dp[i-2]*2)%mod;
                }
                else{
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }
            else if(first=='1' || first=='2'){
                if(second=='*'){
                    if(first=='1'){
                        dp[i]=(dp[i]+dp[i-2]*9)%mod;
                    }
                    else if(first=='2'){
                        dp[i]=(dp[i]+dp[i-2]*6)%mod;
                    }
                }
                else if(((first-'0')*10 + (second-'0'))<=26){
                    dp[i]=(dp[i]+dp[i-2])%mod;
                }
            }
        }
        return dp[n];
    }
};
