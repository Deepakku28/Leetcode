class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=2;
        while(i<n){
            if(nums[i]==nums[i-1] && nums[i-1]==nums[i-2]){
                for(int j=i;j<n-1;j++){
                    nums[j]=nums[j+1];
                }
                n--;
            }
            else{
                i++;
            }
        }
        return n;
    }
};
