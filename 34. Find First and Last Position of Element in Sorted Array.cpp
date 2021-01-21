class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        int start=0,end=nums.size()-1;
        while(start<=end){
            if(nums[start]>target || target>nums[end]){
                return {-1,-1};
            }
            if(nums[start]==target && nums[end]==target){
                return {start,end};
            }
            else if(nums[start]==target && nums[end]>target){
                end--;
            }
            else if(nums[start]<target && nums[end]==target){
                start++;
            }
            else{
                start++;
                end--;
            }
        }
        return {-1,-1};
    }
};
