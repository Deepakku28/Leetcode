class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
