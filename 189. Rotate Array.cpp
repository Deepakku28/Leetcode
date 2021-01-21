class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(nums.size()<2){
            return;
        }
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.end());
        reverse(nums.begin(),nums.end());
    }
};
