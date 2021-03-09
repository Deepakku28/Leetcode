class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    void dfs(vector<vector<char>> &board,vector<vector<bool>> &visited,int &n,int &m,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m || visited[i][j]==true){
            return;
        }
        visited[i][j]=true;
        if(board[i][j]=='M'){
            board[i][j]='X';
            return;
        }
        else{
            if(board[i][j]=='E'){
                int count=0;
                for(auto it:dir){
                    int x=i+it[0];
                    int y=j+it[1];
                    if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='M'){
                        count++;
                    }
                }
                if(count!=0){
                    board[i][j]=count+'0';
                    return;
                }
                else{
                    board[i][j]='B';
                    for(auto it:dir){
                        int x=i+it[0];
                        int y=j+it[1];
                        if(x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                            dfs(board,visited,n,m,x,y);
                        }
                    }
                }
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        dfs(board,visited,n,m,click[0],click[1]);
        return board;
    }
};
