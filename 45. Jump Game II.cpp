class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return 0;
        }
        int currFarthest=nums[0];
        int nextFarthest=nums[0];
        int jumps=1;
        for(int i=1;i<n-1;i++){
            nextFarthest=max(nextFarthest,i+nums[i]);
            if(i==currFarthest){
                currFarthest=nextFarthest;
                jumps++;
            }
        }
        return jumps;
    }
};
