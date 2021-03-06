class Solution {
public:
    void dfs(vector<int> &curr,vector<vector<int>> &ans,int start,int &n,int &k){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            dfs(curr,ans,i+1,n,k);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(curr,ans,1,n,k);
        return ans;
    }
};
