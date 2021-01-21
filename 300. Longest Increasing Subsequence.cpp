class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<=1){
            return len;
        }
        int ans=INT_MIN;
        vector<int> dp(len,1);
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
                
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
