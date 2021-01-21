class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;i<n,j<n;i++,j++){
                int maxVal=INT_MIN;
                for(int k=i;k<=j;k++){
                    int left = (k==i?0:dp[i][k-1]);
                    int right = (k==j?0:dp[k+1][j]);
                    int currVal=((i==0?1:nums[i-1])*nums[k]*(j==n-1?1:nums[j+1]));
                    int total=left+right+currVal;
                    maxVal=max(maxVal,total);
                }
                dp[i][j]=maxVal;
            }
        }
        return dp[0][n-1];
    }
};
