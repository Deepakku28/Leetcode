class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int count=nums[0];
        for(int i=1;i<n;i++){
            count--;
            if(count<0){
                return false;
            }
            if(nums[i]>count){
                count=nums[i];
            }
        }
        return true;
    }
};
