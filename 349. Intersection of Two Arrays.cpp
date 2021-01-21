class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(auto it:nums1){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:nums2){
            if(mp[it]>0){
                mp[it]=0;
                ans.push_back(it);
            }
        }
        return ans;
    }
};
