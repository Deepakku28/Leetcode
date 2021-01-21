class Solution {
public:
    
    int dfs(int index,vector<bool> &visited,vector<vector<int>>& stones,int &n){
        visited[index]=true;
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false && (stones[i][0]==stones[index][0] || stones[i][1]==stones[index][1])){
                ans+=1+dfs(i,visited,stones,n);
            }
        }
        return ans;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans+=dfs(i,visited,stones,n);
            }
        }
        return ans;
    }
};
