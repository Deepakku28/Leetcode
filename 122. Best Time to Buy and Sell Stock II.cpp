class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            ans=ans+max(prices[i]-prices[i-1],0);
        }
        return ans;
    }
};
