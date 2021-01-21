class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n=time.size();
        vector<int> mp(61,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int rem=time[i]%60;
            mp[rem]++;
        }
        ans+=(mp[0]*(mp[0]-1)/2);
        ans+=(mp[30]*(mp[30]-1)/2);
        for(int i=0;i<30;i++){
            ans+=mp[i]*mp[60-i];
        }
        return ans;
    }
};
