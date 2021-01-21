class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int max_dis=0;
        for(int i=0;i<32;i++){
            int ones=0,zero=0;
            int mask=(1<<i);
            for(int j=0;j<nums.size();j++){
                if((mask&nums[j])){
                    ones++;
                }
                else{
                    zero++;
                }
            }
            max_dis+=(ones*zero);
        }
        return max_dis;
    }
};
