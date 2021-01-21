class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int time=0;
        int freshCount=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    freshCount++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(freshCount<0){
            return -1;
        }
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int len=q.size();
            while(len--){
                pair<int,int> curr=q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x=curr.first+dir[i][0];
                    int y=curr.second+dir[i][1];
                    if(x>=0 && y>=0 && x<m && y<n && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        freshCount--;
                    }
                }
            }
            time++;
        }
        if(freshCount>0){
            return -1;
        }
        return time==0?0:time-1;
    }
};
