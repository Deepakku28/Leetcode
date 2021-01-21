class Solution {
public:
    void dfs(vector<vector<bool>> &visited,vector<vector<int>>& matrix,int prev,int i,int j,int &row,int &col){
        if(i<0 || i>=row || j<0 || j>=col || visited[i][j]==true || prev>matrix[i][j]){
            return;
        }
        visited[i][j]=true;
        dfs(visited,matrix,matrix[i][j],i,j+1,row,col);
        dfs(visited,matrix,matrix[i][j],i+1,j,row,col);
        dfs(visited,matrix,matrix[i][j],i,j-1,row,col);
        dfs(visited,matrix,matrix[i][j],i-1,j,row,col);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row=matrix.size();
        vector<vector<int>> ans;
        if(row==0){
            return ans;
        }
        int col=matrix[0].size();
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            dfs(pacific,matrix,-1,i,0,row,col);
            dfs(atlantic,matrix,-1,i,col-1,row,col);
        }
        for(int i=0;i<col;i++){
            dfs(pacific,matrix,-1,0,i,row,col);
            dfs(atlantic,matrix,-1,row-1,i,row,col);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
