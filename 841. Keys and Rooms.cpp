class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(visited[curr]==true){
                continue;
            }
            visited[curr]=true;
            for(auto it:rooms[curr]){
                if(visited[it]==false){
                    q.push(it);
                }
            }
        }
        for(auto it:visited){
            if(it==false){
                return false;
            }
        }
        return true;
    }
};
