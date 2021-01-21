class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> result(N);
        vector<int> adj[N];
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        for (int i=0;i<N;i++) {
            vector<bool> ans(5,false);
            for(auto it:adj[i]){
                ans[result[it]]=true;
            }
            for(int it=1;it<=4;it++) {
                if(ans[it]==false){
                    result[i]=it;
                }
            }
        }
        return result;
    }
};
