class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int i=0;i<32;i++){
            int sum=0;
            int mask=(1<<i);
            for(auto it:nums){
                if(it&mask){
                    sum++;
                }
            }
            if(sum%3){
                result=(result|mask);
            }
        }
        return result;
    }
};
