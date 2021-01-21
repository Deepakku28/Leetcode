class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val=nums[n/2];
        for(int i=0;i<n;i++){
            sum+=abs(val-nums[i]);
        }
        return sum;
    }
};
