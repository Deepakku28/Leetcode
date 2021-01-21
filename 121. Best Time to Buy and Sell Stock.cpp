class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0){
            return 0;
        }
        int min_price=INT_MAX;
        int max_profit=0;
        for(int i=0;i<len;i++){
            min_price=min(min_price,prices[i]);
            max_profit=max(max_profit,prices[i]-min_price);
        }
        return max_profit;
    }
};
