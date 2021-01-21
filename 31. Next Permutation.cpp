class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k=nums.size()-2;
        while(k>=0 && nums[k] >= nums[k+1]){
            k--;
        }
        if(k==-1){
            reverse(nums,0,nums.size()-1);
            return;
        }
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[k]){
                int temp=nums[k];
                nums[k]=nums[i];
                nums[i]=temp;
                break;
            }
        }
        reverse(nums,k+1,nums.size()-1);
    }
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
        return;
    }
};
