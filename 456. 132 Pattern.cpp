class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        vector<int> minVal(n,INT_MAX);
        minVal[0]=nums[0];
        for(int i=1;i<n;i++){
            minVal[i]=min(minVal[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[i]>nums[s.top()]){
                int val=s.top();
                s.pop();
                if(i>0 && minVal[i-1]<nums[val]){
                    return true;
                }
            }
            s.push(i);
        }
        return false;
    }
};
