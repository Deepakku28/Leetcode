class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int sum=accumulate(accounts[i].begin(),accounts[i].end(),0);
            ans=max(ans,sum);
        }
        return ans;
    }
};
