class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor=0;
        for(auto it:nums){
            all_xor=(all_xor^it);
        }
        int low_bit=(all_xor&(-all_xor));
        vector<int> res(2,0);
        for(auto it:nums){
            if((it&low_bit)==0){
                res[0]=(res[0]^it);
            }
            else{
                res[1]=(res[1]^it);
            }
        }
        return res;
    }
};
