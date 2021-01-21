class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len=nums.size();
        int totalSum=0;
        for(int i=0;i<len;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2==1){
            return false;
        }
        int target=totalSum/2;
        vector<vector<bool>> dp(len+1,vector<bool>(target+1));
        for(int i=0;i<=len;i++){
            for(int j=0;j<=target;j++){
                if(i==0 && j==0){
                    dp[i][j]=true;
                }
                else if(i==0){
                    dp[i][j]=false;
                }
                else if(j==0){
                    dp[i][j]=true;
                }
                else if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[len][target];
    }
};
