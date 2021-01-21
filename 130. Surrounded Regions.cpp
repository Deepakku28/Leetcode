class Solution {
public:
    void dfs(vector<vector<char>>& board,int start,int end,int &row,int &col){
        if(start<0 || start>=row || end<0 || end>=col || board[start][end]!='O'){
            return;
        }
        board[start][end]='N';
        dfs(board,start,end+1,row,col);
        dfs(board,start,end-1,row,col);
        dfs(board,start+1,end,row,col);
        dfs(board,start-1,end,row,col);
    }
    
    void solve(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0){
            return ;
        }
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,row,col);
            }
            if(board[i][col-1]=='O'){
                dfs(board,i,col-1,row,col);
            }
        }
        for(int i=0;i<col;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i,row,col);
            }
            if(board[row-1][i]=='O'){
                dfs(board,row-1,i,row,col);
            }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='N'){
                    board[i][j]='O';
                }
            }
        }
    }
};
