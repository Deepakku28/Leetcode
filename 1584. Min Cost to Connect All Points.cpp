class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> distance(n,INT_MAX);
        vector<bool> visited(n,false);
        distance[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({distance[i],i});
        }
        int ans=0;
        vector<pair<int,int>> arr[n];
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                arr[i].push_back({j,dist});
                arr[j].push_back({i,dist});
            }
        }
        int edges=n;
        while(!pq.empty()){
            int val=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(visited[index]==false){
                visited[index]=true;
                ans+=distance[index];
                for(auto it:arr[index]){
                    int ind=it.first;
                    int weight=it.second;
                    if(visited[ind]==false && distance[ind]>weight){
                        distance[ind]=weight;
                        pq.push({distance[ind],ind});
                    }
                }
            }
        }
        return ans;
    }
};
