class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            vector<int> temp;
            int len=q.size();
            while(len--){
                int curr=q.front();
                q.pop();
                temp.push_back(curr);
                for(auto it:adj[curr]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }
            ans=temp;
        }
        return ans;
    }
};
