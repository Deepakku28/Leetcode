class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &totalPath,vector<int> currPath,int &src,int &dest){
        currPath.push_back(src);
        if(src==dest){
            totalPath.push_back(currPath);
            return;
        }
        for(auto it:graph[src]){
            dfs(graph,totalPath,currPath,it,dest);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> totalPath;
        vector<int> currPath;
        int n=graph.size()-1;
        int src=0;
        dfs(graph,totalPath,currPath,src,n);
        return totalPath;
    }
};
