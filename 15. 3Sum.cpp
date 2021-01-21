class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        if(n==0){
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int low=i+1;
            int high=n-1;
            int target=0-nums[i];
            while(low<high){
                int sum=nums[low]+nums[high];
                if(sum>target){
                    high--;
                }
                else if(sum<target){
                    low++;
                }
                else{
                    vector<int> curr(3,0);
                    curr[0]=(nums[i]);
                    curr[1]=(nums[low]);
                    curr[2]=(nums[high]);
                    ans.push_back(curr);
                    while((low<high) &&(nums[low]==curr[1])){
                        low++;
                    }
                    while((low<high) && high-1>=0 && (nums[high]==curr[2])){
                        high--;
                    }
                }           
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return ans;
    }
};
