/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root,unordered_map<int,int> &mp){
        if(root==NULL){
            return 0;
        }
        int sum=root->val+helper(root->left,mp)+helper(root->right,mp);
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        helper(root,mp);
        int maxCount=0;
        for(auto& it:mp){
            maxCount=max(maxCount,it.second);
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxCount){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
