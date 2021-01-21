class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int maxLen=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int curr=nums[i];
                while(s.find(curr)!=s.end()){
                    curr++;
                }
                maxLen=max(maxLen,curr-nums[i]);
            }
        }
        return maxLen;
    }
};
