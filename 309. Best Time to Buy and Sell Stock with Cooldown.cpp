class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0){
            return 0;
        }
        int oldBuyProfit=-prices[0];
        int oldSoldProfit=0;
        int oldCoolProfit=0;
        for(int i=1;i<n;i++){
            int newBuyProfit=0;
            int newSoldProfit=0;
            int newCoolProfit=0;
            if(oldCoolProfit-prices[i]>oldBuyProfit){
                newBuyProfit=oldCoolProfit-prices[i];
            }
            else{
                newBuyProfit=oldBuyProfit;
            }
            if(oldBuyProfit+prices[i]>oldSoldProfit){
                newSoldProfit=oldBuyProfit+prices[i];
            }
            else{
                newSoldProfit=oldSoldProfit;
            }
            if(oldSoldProfit>oldCoolProfit){
                newCoolProfit=oldSoldProfit;
            }
            else{
                newCoolProfit=oldCoolProfit;
            }
            oldSoldProfit=newSoldProfit;
            oldBuyProfit=newBuyProfit;
            oldCoolProfit=newCoolProfit;
        }
        return oldSoldProfit;
    }
};
