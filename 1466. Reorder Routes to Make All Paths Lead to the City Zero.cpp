class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> visited(n,false);
        vector<vector<int>> adj(n),revAdj(n);
        queue<int> q;
        q.push(0);
        int ans=0;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            revAdj[it[1]].push_back(it[0]);
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            visited[curr]=true;
            for(auto it:adj[curr]){
                if(visited[it]==false){
                    ans++;
                    q.push(it);
                }
            }
            for(auto it:revAdj[curr]){
                if(visited[it]==false){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
