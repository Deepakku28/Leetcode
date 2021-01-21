class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>>> graph(N);
        for(auto it:times){
            graph[it[0]-1].push_back({it[1]-1,it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(N,INT_MAX);
        dist[K-1]=0;
        pq.push({0,K-1});
        while(!pq.empty()){
            pair<int,int> curr=pq.top();
            pq.pop();
            int src=curr.second;
            for(auto it:graph[src]){
                if(dist[it.first]>dist[src]+it.second){
                    dist[it.first]=dist[src]+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(auto it:dist){
            if(it==INT_MAX){
                return -1;
            }
            ans=max(ans,it);
        }
        return ans;
    }
};
