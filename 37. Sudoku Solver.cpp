class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int &row,int &col,char &num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if(board[i][col]==num){
                return false;
            }
        }

        int rowStart=row-row%3;
        int colStart=col-col%3;
        for(int i=rowStart;i<rowStart+3;i++){
            for(int j=colStart;j<colStart+3;j++){
                if(board[i][j]==num){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solveSudokuUtil(vector<vector<char>>& board){
        int row=-1;
        int col=-1;
        bool isEmpty=false;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    row=i;
                    col=j;
                    isEmpty=true;
                    break;
                }
            }
            if(isEmpty==true){
                break;
            }
        }
        if(isEmpty==false){
            return true;
        }
        
        for(char num='1';num<='9';num++){
            if(isSafe(board,row,col,num)){
                board[row][col]=num;
                if(solveSudokuUtil(board)){
                    return true;
                }
                else{
                    board[row][col]='.';
                }
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuUtil(board);
        return ;
    }
};
