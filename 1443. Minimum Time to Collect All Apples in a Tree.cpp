class Solution {
public:
    int dfs(vector<vector<int>> &adj,vector<bool>& hasApple,vector<int> &visited,int index,int time){
        visited[index]=1;
        int ans=0;
        for(auto it:adj[index]){
            if(visited[it]==0){
                ans+=dfs(adj,hasApple,visited,it,2);
            }
        }
        if(ans==0 && hasApple[index]==false){
            return 0;
        }
        else{
            return ans+time;
        }
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int edge=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edge;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n,0);
        return dfs(adj,hasApple,visited,0,0);
    }
};
