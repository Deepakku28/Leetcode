class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> &curr,vector<int>& candidates,int &target,int &n,int sum,int start){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<n;i++){
            if(sum<=target){
                curr.push_back(candidates[i]);
                dfs(ans,curr,candidates,target,n,sum+candidates[i],i);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n=candidates.size();
        dfs(ans,curr,candidates,target,n,0,0);
        return ans;
    }
};
