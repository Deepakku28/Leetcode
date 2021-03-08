class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<richer.size();i++){
            adj[richer[i][0]].push_back(richer[i][1]);
        }
        vector<int> degree(n,0);
        for(auto it:adj){
            for(auto itr:it){
                degree[itr]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=i;
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(quiet[ans[it]]>quiet[ans[curr]]){
                    ans[it]=ans[curr];
                }
                degree[it]--;
                if(degree[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
