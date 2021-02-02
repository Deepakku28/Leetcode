class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> &curr,vector<int>& candidates,int &target,int &n,int sum,int start){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<n;i++){
            if(sum<=target){
                if(i>start && candidates[i]==candidates[i-1]){
                    continue;
                }
                curr.push_back(candidates[i]);
                dfs(ans,curr,candidates,target,n,sum+candidates[i],i+1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        dfs(ans,curr,candidates,target,n,0,0);
        return ans;
    }
};
