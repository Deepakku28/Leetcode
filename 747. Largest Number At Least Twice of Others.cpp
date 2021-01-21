class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=-1;
        int firstMax=-1;
        int secondMax=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>firstMax){
                secondMax=firstMax;
                firstMax=nums[i];
                maxIndex=i;
            }
            else if(nums[i]>secondMax){
                secondMax=nums[i];
            }
        }
        if(secondMax*2<=firstMax){
            return maxIndex;
        }
        return -1;
    }
};
