class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size();
        int maxSum=INT_MIN;
        int currMaxSum=0;
        for(int i=0;i<n;i++){
            currMaxSum+=A[i];
            maxSum=max(maxSum,currMaxSum);
            if(currMaxSum<0){
                currMaxSum=0;
            }
        }
        if(maxSum<0){
            return maxSum;
        }
        
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=A[i];
        }
        int minSum=INT_MAX;
        int currMinSum=0;
        for(int i=0;i<n;i++){
            currMinSum+=A[i];
            minSum=min(minSum,currMinSum);
            if(currMinSum>0){
                currMinSum=0;
            }
        }
        return max(maxSum,totalSum-minSum);
    }
};
