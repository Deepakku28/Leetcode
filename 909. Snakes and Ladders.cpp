class Solution {
public:
    pair<int,int> cordinate(int x,int n){
        int r=n-((x-1)/n)-1;
        int c=(x-1)%n;
        if(r%2==n%2){
            return {r,n-c-1};
        }
        return {r,c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        int steps=0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int len=q.size();
            while(len--){
                int curr=q.front();
                q.pop();
                if(curr==n*n){
                    return steps;
                }
                for(int i=1;i<=6;i++){
                    if(curr+i>n*n){
                        break;
                    }
                    pair<int,int> p=cordinate(curr+i,n);
                    if(visited[p.first][p.second]==true){
                        continue;
                    }
                    visited[p.first][p.second]=true;
                    if(board[p.first][p.second]!=-1){
                        q.push(board[p.first][p.second]);
                    }
                    else{
                        q.push(curr+i);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
