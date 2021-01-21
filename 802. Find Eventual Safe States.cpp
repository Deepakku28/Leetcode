class Solution {
public:
    void dfs(vector<vector<int>> &adj,int src,vector<bool> &visited,vector<bool> &inQueue,vector<bool> &cycle){
        if(visited[src]==false){
            visited[src]=true;
            inQueue[src]=true;
            for(auto it:adj[src]){
                if(visited[it]==false){
                    dfs(adj,it,visited,inQueue,cycle);
                }
                if(inQueue[it]==true || cycle[it]==true){
                    cycle[src]=true;
                }
            }
        }
        inQueue[src]=false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<bool> visited(n,false);
        vector<bool> inQueue(n,false);
        vector<bool> cycle(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(adj,i,visited,inQueue,cycle);
            }
        }
        for(int i=0;i<n;i++){
            if(cycle[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
