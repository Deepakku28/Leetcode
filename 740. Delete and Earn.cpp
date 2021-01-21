class Solution {
public:
    int solution(int index,int &end,vector<int>& nums,vector<int>& dp){
        if(index==end){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int element=nums[index];
        int nextIndex=index;
        int sum=0;
        while(nextIndex<end && nums[nextIndex]==element){
            nextIndex++;
            sum+=element;
        }
        while(nextIndex<end && nums[nextIndex]==element+1){
            nextIndex++;
        }
        int ans=max(sum+solution(nextIndex,end,nums,dp),solution(index+1,end,nums,dp));
        return dp[index]=ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n+1,-1);
        return solution(0,n,nums,dp);
    }
};
