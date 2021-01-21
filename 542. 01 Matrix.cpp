class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> ans(row,vector<int>(col,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(auto it:direction){
                int x=curr.first+it[0];
                int y=curr.second+it[1];
                if(x>=0 && x<row && y>=0 && y<col && ans[x][y]==-1){
                    q.push({x,y});
                    ans[x][y]=ans[curr.first][curr.second]+1;
                }
            }
        }
        return ans;
    }
};
