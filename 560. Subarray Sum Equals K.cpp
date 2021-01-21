class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int count=0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i=0;i<n;i++){
            count+=mp[nums[i]-k];
            mp[nums[i]]++;
        }
        return count;
    }
};
