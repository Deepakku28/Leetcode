class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0){
            for(int i=0;i<n-1;i++){
                if(nums[i]==0 && nums[i+1]==0){
                    return true;
                }
            }
            return false;
        }
        for(int i=0;i<n-1;i++){
            int sum=nums[i];
            for(int j=i+1;j<n;j++) {
                sum=sum+nums[j];
                if(sum%k==0){
                    return true;
                }
            }
        }
        return false;
    }
};
