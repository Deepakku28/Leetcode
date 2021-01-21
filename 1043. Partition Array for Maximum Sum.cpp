class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int len=arr.size();
        vector<int> dp(len,0);
        dp[0]=arr[0];
        int curr_max=arr[0];
        for(int i=1;i<k;i++){
            curr_max=max(curr_max,arr[i]);
            dp[i]=(curr_max*(i+1));
        }
        for(int i=k;i<len;i++){
            int subarray_max=arr[i];
            for(int subarray_size=1;subarray_size<=k;subarray_size++){
                subarray_max=max(subarray_max,arr[i-subarray_size+1]);
                dp[i]=max(dp[i],dp[i-subarray_size]+subarray_max*subarray_size);
            }
        }
        return dp[len-1];
    }
};
