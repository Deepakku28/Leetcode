class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> key(n,vector<int>(m,INT_MAX));
        vector<vector<int>> direction={{-1, 0},{1, 0}, {0, -1}, {0, 1}};
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
        key[0][0]=0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int minEffort=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(minEffort>key[x][y]){
                continue;
            }
            for(auto it:direction){
                int row=x+it[0];
                int col=y+it[1];
                if(row>=0 && row<n && col>=0 && col<m && key[row][col]>max(minEffort,abs(heights[x][y]-heights[row][col]))){
                    pq.push({max(minEffort,abs(heights[x][y]-heights[row][col])),row,col});
                    key[row][col]=max(minEffort,abs(heights[x][y]-heights[row][col]));
                }
            }
        }
        return key[n-1][m-1];
    }
};
