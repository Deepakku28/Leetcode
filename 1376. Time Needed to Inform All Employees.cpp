class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<manager.size();i++){
            mp[manager[i]].push_back(i);
        }
        int ans=0;
        queue<pair<int,int>> q;
        q.push({headID,0});
        while(!q.empty()){
            int n=q.size();
            while(n--){
                auto curr=q.front();
                q.pop();
                ans=max(ans,informTime[curr.first]+curr.second);
                for(auto it:mp[curr.first]){
                    q.push({it,informTime[curr.first]+curr.second});
                }
            }
        }
        return ans;
    }
};
