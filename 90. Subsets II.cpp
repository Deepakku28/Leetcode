class Solution {
public:
    void helper(vector<int> &curr,vector<vector<int>> &ans,vector<int> &nums,int start,int &end){
        if(start>end){
            return;
        }
        ans.push_back(curr);
        for(int i=start;i<end;i++){
            if(i>start && nums[i-1]==nums[i]){
                continue;
            }
            curr.push_back(nums[i]);
            helper(curr,ans,nums,i+1,end);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        helper(curr,ans,nums,0,n);
        return ans;
    }
};
