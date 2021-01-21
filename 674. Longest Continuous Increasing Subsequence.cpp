class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n;
        }
        int maxLen=1;
        int count=1;
        for(int i=0;i<n-1;i++){
            int prevStart=i;
            int nextStart=i+1;
            while(nextStart<n && nums[nextStart]>nums[prevStart]){
                prevStart++;
                nextStart++;
                count++;
            }
            maxLen=max(maxLen,count);
            count=1;
        }
        return maxLen;
    }
};
