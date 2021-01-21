class Solution {
public:
    void dfs(vector<vector<int>> &A,int r,int c,int &row,int &col){
        if(r<0 || r>=row || c<0 || c>=col || A[r][c]==0){
            return ;
        }
        A[r][c]=0;
        dfs(A,r,c+1,row,col);
        dfs(A,r+1,c,row,col);
        dfs(A,r,c-1,row,col);
        dfs(A,r-1,c,row,col);
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int row=A.size();
        if(row==0){
            return 0;
        }
        int col=A[0].size();
        for(int i=0;i<col;i++){
            if(A[0][i]==1){
                dfs(A,0,i,row,col);
            }
            if(A[row-1][i]==1){
                dfs(A,row-1,i,row,col);
            }
        }
        for(int i=0;i<row;i++){
            if(A[i][0]==1){
                dfs(A,i,0,row,col);
            }
            if(A[i][col-1]==1){
                dfs(A,i,col-1,row,col);
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(A[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
