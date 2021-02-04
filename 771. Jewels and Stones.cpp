class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mp;
        for(auto it:stones){
            mp[it]++;
        }
        int ans=0;
        for(auto it:jewels){
            if(mp.find(it)==mp.end()){
                continue;
            }
            ans+=mp[it];
        }
        return ans;
    }
};
