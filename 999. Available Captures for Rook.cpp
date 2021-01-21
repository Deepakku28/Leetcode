class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x=-1,y=-1;
        bool flag=false;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    flag=true;
                }
                if(flag==true){
                    break;
                }
            }
            if(flag==true){
                break;
            }
        }
        int ans=0;
        for(int i=y+1;i<8;i++){
            if(board[x][i]=='.'){
                continue;
            }
            else if(isupper(board[x][i])){
                break;
            }
            else if(islower(board[x][i])){
                ans++;
                break;
            }
        }
        for(int i=y-1;i>=0;i--){
            if(board[x][i]=='.'){
                continue;
            }
            else if(isupper(board[x][i])){
                break;
            }
            else if(islower(board[x][i])){
                ans++;
                break;
            }
        }
        for(int i=x-1;i>=0;i--){
            if(board[i][y]=='.'){
                continue;
            }
            else if(isupper(board[i][y])){
                break;
            }
            else if(islower(board[i][y])){
                ans++;
                break;
            }
        }
        for(int i=x+1;i<8;i++){
            if(board[i][y]=='.'){
                continue;
            }
            else if(isupper(board[i][y])){
                break;
            }
            else if(islower(board[i][y])){
                ans++;
                break;
            }
        }
        return ans;
    }
};
