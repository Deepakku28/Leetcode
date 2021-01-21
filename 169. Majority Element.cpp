class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int len=nums.size();
        for(int i=0;i<len;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>len/2){
                return nums[i];
            }
        }
        return 0;
    }
};
