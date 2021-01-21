class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            if(nums[i]==1){
                while(i<n){
                    if(nums[i]!=1){
                        break;
                    }
                    count++;
                    i++;
                }
            }
            maxLen=max(maxLen,count);
        }
        return maxLen;
    }
};
