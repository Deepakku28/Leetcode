class Solution {
public:
    
    void backtrack(vector<vector<int>>& result,vector<int>& nums,int pos,vector<int>& curr){
        result.push_back(curr);
        for(int i=pos;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(result,nums,i+1,curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result,nums,0,curr);
        return result;
    }
};
