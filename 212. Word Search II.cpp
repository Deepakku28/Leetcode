class Solution {
public:
    bool helper(int i,int j,int &row,int &col,vector<vector<char>> board,vector<vector<int>> &direction,string &it,int len){
        if(len==it.size()){
            return true;
        }
        bool ans=false;
        for(int k=0;k<4;k++){
            int x=i+direction[k][0];
            int y=j+direction[k][1];
            if(x>=0 && x<row && y>=0 && y<col && board[x][y]==it[len]){
                char ch=board[x][y];
                board[x][y]='.';
                if(helper(x,y,row,col,board,direction,it,len+1)){
                    ans=true;
                }
                board[x][y]=ch;
            }
        }
        return ans;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row=board.size();
        int col=board[0].size();
        if(row==0 || col==0 || words.size()==0){
            return {};
        }
        vector<string> ans;
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto &it:words){
            bool flag=false;
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    if(board[i][j]==it[0]){
                        char ch=board[i][j];
                        board[i][j]='.';
                        if(helper(i,j,row,col,board,direction,it,1)){
                            ans.push_back(it);
                            flag=true;
                        }
                        board[i][j]=ch;
                    }
                    if(flag==true){
                        break;
                    }
                }
                if(flag==true){
                    break;
                }
            }
        }
        return ans;
    }
};
