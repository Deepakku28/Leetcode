class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int step=1;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                pair<int,int> curr=q.front();
                q.pop();
                for(auto it:dir){
                    int x=curr.first+it[0];
                    int y=curr.second+it[1];
                    if(x>=0 && x<n && y>=0 && y<m && ans[x][y]==INT_MAX){
                        ans[x][y]=step;
                        q.push({x,y});
                    }
                }
            }
            step++;
        }
        return ans;
    }
};
