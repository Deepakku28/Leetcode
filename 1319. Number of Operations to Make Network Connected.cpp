class Solution {
public:
    void dfs(vector<vector<int>> &adj,int i,vector<int> &visited){
        visited[i]=1;
        for(auto it:adj[i]){
            if(visited[it]==0){
                dfs(adj,it,visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges=connections.size();
        if(edges<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<edges;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adj,i,visited);
                ans++;
            }
        }
        if(ans==0){
            return 0;
        }
        return ans-1;
    }
};
