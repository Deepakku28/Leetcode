class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
        }
        int sum=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            auto it=mp.find(sum);
            if(sum==0){
                maxLen=i+1;
            }
            else if(it!=mp.end()){
                maxLen=max(maxLen,i-it->second);
            }
            else if(it==mp.end()){
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};
