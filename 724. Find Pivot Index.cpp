class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        vector<int> left(n,0);
        left[0]=nums[0];
        vector<int> right(n,0);
        right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]=left[i-1]+nums[i];
            right[n-i-1]=right[n-i]+nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;
    }
};
