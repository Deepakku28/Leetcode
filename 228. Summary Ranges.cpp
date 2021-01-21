class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return {};
        }
        vector<string> res;
        int i=0;
        while(i<n){
            int start=i;
            int end=i;
            while(end+1<n && nums[end+1]==nums[end]+1){
                end++;
            }
            if(end>start){
                res.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            else{
                res.push_back(to_string(nums[start]));
            }
            i=end+1;
        }
        return res;
    }
};
