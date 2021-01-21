class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid.size();
        if(row==0 || col==0 || grid[0][0]!=0 || grid[row-1][col-1]!=0){
            return -1;
        }
        vector<vector<int>> dire={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        q.push(make_pair(0,0));
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            visited[x][y]=true;
            if(x==row-1 && y==col-1){
                return grid[x][y]+1;
            }
            for(auto it:dire){
                int currX=x+it[0];
                int currY=y+it[1];
                if(currX>=0 && currX<row && currY>=0 && currY<col && grid[currX][currY]==0 && visited[currX][currY]==false){
                    grid[currX][currY]=grid[x][y]+1;
                    q.push(make_pair(currX,currY));
                }
            }
        }
        return -1;
    }
};
