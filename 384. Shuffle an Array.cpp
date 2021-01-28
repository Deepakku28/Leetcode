class Solution {
public:
    vector<int> val;
    
    Solution(vector<int>& nums) {
        val=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return val;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans=val;
        for(int i=0;i<ans.size();i++) {
            int pos=(rand()%(ans.size()-i));
            swap(ans[i+pos],ans[i]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
