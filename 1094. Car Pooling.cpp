class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[trips[i][1]]+=trips[i][0];
            mp[trips[i][2]]-=trips[i][0];
        }
        int ans=0;
        for(auto it:mp){
            ans+=it.second;
            if(ans>capacity){
                return false;
            }
        }
        return true;
    }
};
