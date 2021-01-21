class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> temp(m,vector<int>(n,0));
        vector<vector<int>> direction{{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(auto it:direction){
                    int x=i+it[0];
                    int y=j+it[1];
                    if(x<0 || x>=m || y<0 || y>=n){
                        continue;
                    }
                    if(board[x][y]==1){
                        count++;
                    }
                }
                if(board[i][j]==0){
                    if(count==3){
                        temp[i][j]=1;
                    }
                }
                else{
                    if(count==2 || count==3){
                        temp[i][j]=1;
                    }
                    else if(count>3){
                        temp[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=temp[i][j];
            }
        }
    }
};
