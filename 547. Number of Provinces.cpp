class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int &row,int &col,int i,int j,vector<vector<int>> &visited){
        if(i<0 || i>=row || j<0 || j>=col){
            return ;
        }
        visited[i][j]=1;
        visited[j][i]=1;
        for(int k=0;k<col;k++){
            if(visited[j][k]==0 && isConnected[j][k]==1){
                dfs(isConnected,row,col,j,k,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int row=isConnected.size();
        int col=isConnected[0].size();
        int ans=0;
        vector<vector<int>> visited(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(visited[i][j]==0 && isConnected[i][j]==1){
                    dfs(isConnected,row,col,i,j,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};
