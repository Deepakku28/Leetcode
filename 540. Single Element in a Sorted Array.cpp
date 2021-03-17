class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n;
        if(n==1){
            return nums[0];
        }
        while(start<end){
            int mid=(start+end)/2;
            if(mid%2){
                mid--;
            }
            if(nums[mid]!=nums[mid+1]){
                end=mid;
            }
            else{
                start=mid+2;
            }
        }
        return nums[start];
    }
};
