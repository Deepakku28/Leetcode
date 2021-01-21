class Solution {
public:
    long long min(long long a,long long b){
        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }
    
    int minMoves(vector<int>& nums) {
        long long sum=0;
        long long n=nums.size();
        long long minVal=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minVal=min(minVal,nums[i]);
        }
        return (int)(sum-n*minVal);
    }
};
