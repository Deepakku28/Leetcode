class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return 0;
        }
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                right[i]=right[i+1]+1;
            }
        }
        int maxLen=0;
        for(int i=0;i<n;i++){
            if(left[i]!=0 && right[i]!=0){
                maxLen=max(maxLen,left[i]+right[i]+1);
            }
        }
        return maxLen;
    }
};
