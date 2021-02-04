class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int ind=index[i];
            int val=nums[i];
            ans.insert(ans.begin()+ind,val);
        }
        return ans;
    }
};
