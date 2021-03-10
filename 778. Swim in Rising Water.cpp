class Solution {
public:
    bool check(int upperLimit,int &n,vector<vector<int>> &grid){
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();
            if(grid[curr.first][curr.second]<=upperLimit){
                if(curr.first==n-1 && curr.second==n-1){
                    return true;
                }
                for(auto it:dir){
                    int x=curr.first+it[0];
                    int y=curr.second+it[1];
                    if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==false){
                        visited[x][y]=true;
                        q.push({x,y});
                    }
                }
            }
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int left=0;
        int right=n*n-1;
        while(left<right){
            int mid=(left+right)/2;
            if(check(mid,n,grid)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;
    }
};
