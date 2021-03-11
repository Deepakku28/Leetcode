class Solution {
public:
    void helper(vector<int> nums,vector<vector<int>> &ans,int start,int &end){
        if(start==end){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<=end;i++){
            if(i!=start && nums[i]==nums[start]){
                continue;
            }
            swap(nums[i],nums[start]);
            helper(nums,ans,start+1,end);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        helper(nums,ans,0,n);
        return ans;
    }
};
