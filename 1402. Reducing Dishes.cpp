class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end(),greater());
        int n=satisfaction.size();
        int prefixSum=0;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            prefixSum+=satisfaction[i];
            sum+=prefixSum;
            ans=max(ans,sum);
        }
        return ans;
    }
};
