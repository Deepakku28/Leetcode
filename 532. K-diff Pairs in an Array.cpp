class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=1;
        int ans=0;
        int prevLeft=INT_MIN;
        while(right<n){
            int diff=nums[right]-nums[left];
            if(diff==k){
                if(nums[left]!=prevLeft){
                    ans++;
                }
                prevLeft=nums[left];
                left++;
            }
            else if(diff<k){
                right++;
            }
            else if(diff>k){
                left++;
            }
            if(left==right){
                right++;
            }
        }
        return ans;
    }
};
