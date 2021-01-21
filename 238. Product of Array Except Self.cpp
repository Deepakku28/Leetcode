class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int countZero=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }
            else{
                countZero++;
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && countZero==0){
                ans[i]=prod/nums[i];
            }
            else if(nums[i]!=0 && countZero>0){
                ans[i]=0;
            }
            else if(nums[i]==0 && countZero==1){
                ans[i]=prod;
            }
            else if(nums[i]==0 && countZero>1){
                ans[i]=0;
            }
        }
        return ans;
    }
};
