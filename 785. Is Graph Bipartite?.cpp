class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                q.push(i);
            }
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto it:graph[curr]){
                    if(color[it]==-1){
                        color[it]=1-color[curr];
                        q.push(it);
                    }
                    else if(color[it]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
