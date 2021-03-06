class Solution {
public:
    void dfs(vector<int> &curr,vector<vector<int>> &ans,int start,int n,int &k){
        if(n==0 && curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            dfs(curr,ans,i+1,n-i,k);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(curr,ans,1,n,k);
        return ans;
    }
};
