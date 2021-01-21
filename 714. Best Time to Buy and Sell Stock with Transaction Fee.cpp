class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int oldBuyProfit=-prices[0];
        int oldSoldProfit=0;
        for(int i=1;i<n;i++){
            int newBuyProfit=0;
            int newSoldProfit=0;
            if(oldSoldProfit-prices[i]>oldBuyProfit){
                newBuyProfit=oldSoldProfit-prices[i];
            }
            else{
                newBuyProfit=oldBuyProfit;
            }
            if(oldBuyProfit+prices[i]-fee>oldSoldProfit){
                newSoldProfit=oldBuyProfit+prices[i]-fee;
            }
            else{
                newSoldProfit=oldSoldProfit;
            }
            oldSoldProfit=newSoldProfit;
            oldBuyProfit=newBuyProfit;
        }
        return oldSoldProfit;
    }
};
