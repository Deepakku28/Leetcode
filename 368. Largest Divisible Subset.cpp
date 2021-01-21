class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(len,1);
        vector<int> result;
        int maxLen=1;
        for(int i=1;i<len;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
            maxLen=max(maxLen,dp[i]);
        }
        int temp=maxLen;
        for(int i=len-1;i>=0 && maxLen>=1;i--){
            if(dp[i]==maxLen && maxLen==temp){
                result.push_back(nums[i]);
                maxLen--;
            }
            
            else if(dp[i]==maxLen && result.back()%nums[i]==0){
                result.push_back(nums[i]);
                maxLen--;
            }
        }
        return result;;
    }
};
