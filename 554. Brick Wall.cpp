class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size()==0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int i=0;i<wall.size();i++){
            int sum=0;
            for(int j=0;j<wall[i].size();j++){
                sum+=wall[i][j];
                mp[sum]++;
            }
        }
        int sum=0;
        for(int i=0;i<wall[0].size();i++){
            sum+=wall[0][i];
        }
        mp.erase(sum);
        int ans=0;
        for(auto it:mp){
            ans=max(ans,it.second);
        }
        return (wall.size()-ans);
    }
};
