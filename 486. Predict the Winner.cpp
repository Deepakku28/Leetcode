class Solution {
public:
    int solution(int start,int end,vector<vector<int>> &dp,vector<int>& nums){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        return max(nums[start]+min(solution(start+1,end-1,dp,nums),solution(start+2,end,dp,nums)),
                  nums[end]+min(solution(start+1,end-1,dp,nums),solution(start,end-2,dp,nums)));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return true;
        }
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int firstSum=solution(0,n-1,dp,nums);
        int secondSum=sum-firstSum;
        return (firstSum>=secondSum);
    }
};
