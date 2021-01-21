class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n<=0){
            return 0;
        }
        int globalMax=*max_element(nums.begin(),nums.end()), currMax=0;
        if(globalMax<0){
            return globalMax;
        }
        for(int i=0;i<n;i++){
            currMax=currMax+nums[i];
            if(currMax<0){
                currMax=0;
            }
            globalMax=max(globalMax,currMax);
        }
        return globalMax;
    }
};
