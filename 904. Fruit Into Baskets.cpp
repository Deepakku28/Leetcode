class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n=tree.size();
        int start=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[tree[i]]++;
            while(mp.size()>2 && start<i){
                mp[tree[start]]--;
                if(mp[tree[start]]==0){
                    mp.erase(tree[start]);
                }
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
