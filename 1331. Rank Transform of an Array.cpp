class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> sorted=arr;
        sort(sorted.begin(),sorted.end());
        unordered_map<int,int> mp;
        int rank=1;
        for(int i=0;i<n;i++){
            if(mp.find(sorted[i])==mp.end()){
                mp[sorted[i]]=rank;
                rank++;
            }
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};
