class Solution {
public:
    
    void solution(int index,vector<int> &curr,vector<vector<int>> &ans,vector<int>& nums){
        if(nums.size()==index){
            if(curr.size()>=2){
                ans.push_back(curr);
            }
            return ;
        }
        if(curr.empty() || !curr.empty() && curr.back()<=nums[index]){
            curr.push_back(nums[index]);
            solution(index+1,curr,ans,nums);
            curr.pop_back();
        }
        if(curr.empty() || !curr.empty() && curr.back()!=nums[index]){
            //curr.push_back(nums[index]);
            solution(index+1,curr,ans,nums);
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        solution(0,curr,ans,nums);
        return ans;
    }
};
