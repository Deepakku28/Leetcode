class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        while(start<=end && sorted[start]==nums[start]){
            start++;
        }
        while(start<end && sorted[end]==nums[end]){
            end--;
        }
        return (end-start+1);
    }
};
