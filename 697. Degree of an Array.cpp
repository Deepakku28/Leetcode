class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,vector<int>> pos;
        int maxFreq=1;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
            maxFreq=max(maxFreq,freq[nums[i]]);        
            pos[nums[i]].push_back(i);
        }
        int maxLen=nums.size();
        for(auto it:nums){
            if(freq[it]==maxFreq){
                maxLen=min(maxLen,pos[it].back()-pos[it].front());
            }
        }
        return maxLen+1;
    }
};
