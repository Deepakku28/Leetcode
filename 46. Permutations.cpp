class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &ans,int start,int &end){
        if(start==end){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<=end;i++){
            swap(nums[i],nums[start]);
            helper(nums,ans,start+1,end);
            swap(nums[i],nums[start]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size()-1;
        vector<vector<int>> ans;
        helper(nums,ans,0,n);
        return ans;
    }
};
