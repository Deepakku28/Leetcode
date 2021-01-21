class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        vector<pair<int,int>> sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({difficulty[i],profit[i]});
        }
        sort(sorted.begin(),sorted.end());
        sort(worker.begin(),worker.end());
        int j=0;
        int maxProfit=0;
        int m=worker.size();
        int currMax=0;
        for(int i=0;i<m;i++){
            while(j<n && worker[i]>=sorted[j].first){
                currMax=max(currMax,sorted[j].second);
                j++;
            }
            maxProfit+=currMax;
        }
        return maxProfit;
    }
};
