class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum=0;
        int ans=0;
        for(auto it:A){
            sum+=it;
            ans+=mp[sum-S];
            mp[sum]++;
        }
        return ans;
    }
};
