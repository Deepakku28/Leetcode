class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int land=0;
        int water=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    land++;
                    q.push({i,j});
                }
                else{
                    water++;
                }
            }
        }
        if(land==0 || water==0){
            return -1;
        }
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int step=0;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                pair<int,int> curr=q.front();
                q.pop();
                for(auto it:dir){
                    int x=curr.first+it[0];
                    int y=curr.second+it[1];
                    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0){
                        grid[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            if(q.empty()){
                return step;
            }
            step++;
        }
        return step;
    }
};
