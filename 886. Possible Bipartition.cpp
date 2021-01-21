class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> graph[N];
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]-1].push_back(dislikes[i][1]-1);
            graph[dislikes[i][1]-1].push_back(dislikes[i][0]-1);
        }
        vector<int> color(N,-1);
        queue<int> q;
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                color[i]=1;
                q.push(i);
            }
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(auto it:graph[curr]){
                    if(color[it]==-1){
                        color[it]=1-color[curr];
                        q.push(it);
                    }
                    else if(color[it]==color[curr]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
