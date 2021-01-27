class Solution {
public:
    bool helper(int i,int j,int &row,int &col,vector<vector<char>> board,vector<vector<int>> &direction,string &word,int len){
        if(len>=word.size()){
            return true;
        }
        for(int k=0;k<4;k++){
            int x=i+direction[k][0];
            int y=j+direction[k][1];
            if(x>=0 && x<row && y>=0 && y<col && board[x][y]==word[len]){
                char ch=board[i][j];
                board[i][j]='.';
                if(helper(x,y,row,col,board,direction,word,len+1)){
                    return true;
                }
                board[i][j]=ch;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    char ch=board[i][j];
                    board[i][j]='.';
                    if(helper(i,j,row,col,board,direction,word,1)){
                        return true;
                    }
                    board[i][j]=ch;
                }
            }
        }
        return false;
    }
};
