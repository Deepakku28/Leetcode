class Solution {
public:
    int helper(vector<vector<vector<long long int>>> &dp,int index,int &n,int count,int &k,int buyOrSell,vector<int>& prices){
        if(count>=k || index>=n){
            return 0;
        }
        else if(dp[index][buyOrSell][count]!=-1){
            return dp[index][buyOrSell][count];
        }
        if(buyOrSell){
            return dp[index][buyOrSell][count]=max(-prices[index]+helper(dp,index+1,n,count,k,0,prices),
                                                  helper(dp,index+1,n,count,k,buyOrSell,prices));
        }
        else{
            return dp[index][buyOrSell][count]=max(prices[index]+helper(dp,index+1,n,count+1,k,1,prices),
                                                  helper(dp,index+1,n,count,k,buyOrSell,prices));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(2*k>=n){
            int res=0;
            for(int i=1;i<n;i++) {
                res+=max(0,prices[i]-prices[i-1]);
            }
            return res;
        }
        vector<vector<vector<long long int>>> dp(n+1,vector<vector<long long int>>(2,vector<long long int>(k+1,-1)));
        return helper(dp,0,n,0,k,1,prices);
    }
};
