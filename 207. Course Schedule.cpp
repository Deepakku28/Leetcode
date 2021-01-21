class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        for(auto it:prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        for(auto adj:graph){
            for(auto it:adj){
                degree[it]++;
            }
        }
        vector<int> result;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for(auto it:graph[curr]){
                degree[it]--;
                if(degree[it]==0){
                    q.push(it);
                }
            }
        }
        return (n==result.size());
    }
};
