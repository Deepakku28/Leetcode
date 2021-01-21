class Solution {
public:
    void dfs(vector<vector<int>> &A,vector<vector<bool>> &visited,queue<pair<int,int>> &q,int &row,int &col,int i,int j){
        if(i<0 || i>=row || j<0 || j>=col || A[i][j]==0 || visited[i][j]==true){
            return;
        }
        q.push({i,j});
        visited[i][j]=true;
        dfs(A,visited,q,row,col,i,j+1);
        dfs(A,visited,q,row,col,i+1,j);
        dfs(A,visited,q,row,col,i,j-1);
        dfs(A,visited,q,row,col,i-1,j);
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        int row=A.size();
        int col=A[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        queue<pair<int,int>> q;
        bool found=false;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(A[i][j]==1){
                    dfs(A,visited,q,row,col,i,j);
                    found=true;
                    break;
                }
            }
            if(found==true){
                break;
            }
        }
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        int steps=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto curr=q.front();
                q.pop();
                for(auto it:direction){
                    int x=curr.first+it[0];
                    int y=curr.second+it[1];
                    if(x>=0 && x<row && y>=0 && y<col && visited[x][y]==false){
                        visited[x][y]=true;
                        if(A[x][y]==1){
                            return steps;
                        }
                        q.push({x,y});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
