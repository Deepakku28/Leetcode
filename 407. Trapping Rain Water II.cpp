class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m=heightMap.size();
        int n=heightMap[0].size();
        if(m<3 || n<3){
            return 0;
        }
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(heightMap[0][i],make_pair(0,i)));
            pq.push(make_pair(heightMap[m-1][i],make_pair(m-1,i)));
            visited[0][i]=true;
            visited[m-1][i]=true;
        }
        for(int i=1;i<m-1;i++){
            pq.push(make_pair(heightMap[i][0],make_pair(i,0)));
            pq.push(make_pair(heightMap[i][n-1],make_pair(i,n-1)));
            visited[i][0]=true;
            visited[i][n-1]=true;
        }
        int ans=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> curr=pq.top();
            int height=curr.first;
            int currx=curr.second.first;
            int curry=curr.second.second;
            pq.pop();
            for(auto it:dir){
                int newx=currx+it[0];
                int newy=curry+it[1];
                if(newx>=1 && newx<=m-2 && newy>=1 && newy<=n-2 && visited[newx][newy]==false){
                    visited[newx][newy]=true;
                    if(heightMap[newx][newy]<heightMap[currx][curry]){
                        ans=ans+heightMap[currx][curry]-heightMap[newx][newy];
                        heightMap[newx][newy]=heightMap[currx][curry];
                    }
                    pq.push(make_pair(heightMap[newx][newy],make_pair(newx,newy)));
                }
            }
        }
        return ans;
    }
};
