class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            string str=to_string(nums[i]);
            if((int)str.size()%2==0){
                ans++;
            }
        }
        return ans;
    }
};
