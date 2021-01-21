class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==target){
                    return target;
                }
                else if(sum<target){
                    start++;
                }
                else{
                    end--;
                }
                if(abs(target-sum)<abs(target-ans)){
                    ans=sum;
                }
            }
        }
        return ans;
    }
};
