class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int ans=1;
        for(auto it:s){
            if(it<=0){
                continue;
            }
            else if(it==ans){
                ans++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};
