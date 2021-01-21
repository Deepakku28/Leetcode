class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int left=0,right=nums.size()-1;
        while(left<right){
            int midpoint= left +(right-left)/2;
            if(nums[midpoint]>nums[right]){
                left=midpoint+1;
            }
            else{
                right=midpoint;
            }
        }
        
        int start=left;
        left=0;
        right=nums.size()-1;
        
        if(target>=nums[start] && target<=nums[right]){
            left=start;
        }
        else{
            right=start;
        }
        
        while(left<=right){
            int midpoint=left+(right-left)/2;
            if(target==nums[midpoint]){
                return midpoint;
            }
            else if(target>nums[midpoint]){
                left=midpoint+1;
            }
            else{
                right=midpoint-1;
            }
        }
        return -1;
    }
};
