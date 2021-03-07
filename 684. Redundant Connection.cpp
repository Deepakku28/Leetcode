class Solution {
public:
    int find(int val,vector<int> &parent){
        if(val==parent[val]){
            return val;
        }
        return parent[val]=find(parent[val],parent);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(1001,-1);
        for(int i=0;i<=1000;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            int first=find(edges[i][0],parent);
            int second=find(edges[i][1],parent);
            if(first==second){
                return {edges[i][0],edges[i][1]};
            }
            else{
                parent[second]=first;
            }
        }
        return {};
    }
};
