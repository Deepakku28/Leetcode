class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int n=prices.size();
        vector<int> left(n,0);
        int minLeft=prices[0];
        for(int i=1;i<n;i++){
            minLeft=min(minLeft,prices[i]);
            left[i]=max(left[i-1],prices[i]-minLeft);
        }
        
        vector<int> right(n,0);
        int maxRight=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxRight=max(maxRight,prices[i]);
            right[i]=max(right[i+1],maxRight-prices[i]);
        }
        
        int result=0;
        for(int i=0;i<n;i++){
            result=max(left[i]+right[i],result);
        }
        return result;
    }
};
