class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double ans=INT_MIN;
        int n=nums.size();
        for(int i=0;i<min(n,k);i++){
            sum+=nums[i];
        }
        for(int i=k;i<n;i++){
            ans=max(ans,sum);
            sum+=nums[i]-nums[i-k];
        }
        ans=max(ans,sum);
        return (ans/k);
    }
};
