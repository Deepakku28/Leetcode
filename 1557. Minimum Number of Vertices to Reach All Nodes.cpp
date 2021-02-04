class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto it:edges){
            indegree[it[1]]++;
        }
        vector<int> val;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                val.push_back(i);
            }
        }
        return val;
    }
};
