class Solution {
public:
    int findMin(vector<int>& nums) {
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
        return nums[left];
    }
};
