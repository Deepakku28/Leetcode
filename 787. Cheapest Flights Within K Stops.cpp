class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>> graph[n];
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push(make_pair(0,make_pair(src,K+1)));
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            if(curr.second.first==dst){
                return curr.first;
            }
            if(curr.second.second<=0){
                continue;
            }
            for(auto it:graph[curr.second.first]){
                pq.push(make_pair(curr.first+it.second,make_pair(it.first,curr.second.second-1)));
            }
        }
        return -1;
    }
};
