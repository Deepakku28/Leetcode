class Solution {
public:
    int dfs(int i,int j,int &m,int &n,vector<vector<int>>& grid,int &islandId){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1){
            return 0;
        }
        grid[i][j]=islandId;
        int curr=1;
        return curr+=dfs(i,j+1,m,n,grid,islandId)+dfs(i+1,j,m,n,grid,islandId)+dfs(i,j-1,m,n,grid,islandId)+dfs(i-1,j,m,n,grid,islandId);
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0){
            return 0;
        }
        int islandId=2;
        unordered_map<int,int> mp;
        int maxArea=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int area=dfs(i,j,m,n,grid,islandId);
                    maxArea=max(maxArea,area);
                    mp[islandId]=area;
                    islandId++;
                }
            }
        }
        
        vector<vector<int>> direction{{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> s;
                    for(auto it:direction){
                        int x=it[0]+i;
                        int y=it[1]+j;
                        if(x>=0 && y>=0 && x<m && y<n && grid[x][y]!=0){
                            s.insert(grid[x][y]);
                        }
                    }
                    int tempArea=1;
                    for(auto it:s){
                        tempArea+=mp[it];
                    }
                    maxArea=max(maxArea,tempArea);
                }
            }
        }
        return maxArea;
    }
};
