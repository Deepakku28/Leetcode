class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len=nums.size();
        int N=len-k+1;
        int dp[N];
        int sum=0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
            if(i>=k){
                sum-=nums[i-k];
            }
            if(i>=k-1){
                dp[i-k+1]=sum;
            }
        }
        int left[N];
        int right[N];
        int max_index=0;
        for(int i=0;i<N;i++){
            if(dp[i]>dp[max_index]){
                max_index=i;
            }
            left[i]=max_index;
        }
        max_index=N-1;
        for(int i=N-1;i>=0;i--){
            if(dp[i]>=dp[max_index]){
                max_index=i;
            }
            right[i]=max_index;
        }
        vector<int> ans(3,-1);
        for(int i=k;i<N-k;i++){
            if(ans[0]==-1 || dp[ans[0]]+dp[ans[1]]+dp[ans[2]]<dp[left[i-k]]+dp[i]+dp[right[i+k]]){
                ans[0]=left[i-k];
                ans[1]=i;
                ans[2]=right[i+k];
            }
        }
        return ans;
    }
};
