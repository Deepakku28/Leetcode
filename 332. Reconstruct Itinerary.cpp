class Solution {
public:
    void dfs(string start,unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &mp,vector<string> &ans){
        while(!mp[start].empty()){
            string curr=mp[start].top();
            mp[start].pop();
            dfs(curr,mp,ans);
        }
        ans.push_back(start);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> mp;
        for(int i=0;i<tickets.size();i++){
            for(int j=1;j<tickets[0].size();j++){
                mp[tickets[i][0]].push(tickets[i][j]);
            }
        }
        vector<string> ans;
        dfs("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
