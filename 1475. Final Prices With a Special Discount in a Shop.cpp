class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        stack<int> s;
        vector<int> discount(n,0);
        for(int i=n-1;i>=0;i--){
            if(!s.empty()){
                if(prices[s.top()]<=prices[i]){
                    discount[i]=prices[s.top()];
                }
                else{
                    while(!s.empty() && prices[s.top()]>prices[i]){
                        s.pop();
                    }
                    if(!s.empty()){
                        discount[i]=prices[s.top()];
                    }
                }
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            prices[i]-=discount[i];
        }
        return prices;
    }
};
