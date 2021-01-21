class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long max1=-1e15;
        long max2=-1e15;
        long max3=-1e15;
        for(int i=0;i<n;i++){
            if(nums[i]==max1 || nums[i]==max2 || nums[i]==max3){
                continue;
            }
            else if(max1==-1e15 || nums[i]>max1) {
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(max2==-1e15 || nums[i]>max2) {
                max3=max2;
                max2=nums[i];
            }
            else if(max3==-1e15 || nums[i]>max3) {
                max3=nums[i];
            }
        }
        return max3==-1e15?max1:max3;
    }
};
