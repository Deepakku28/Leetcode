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
    void helper(TreeNode* root,vector<int> &val){
        if(root==NULL){
            return;
        }
        helper(root->left,val);
        val.push_back(root->val);
        helper(root->right,val);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> val;
        helper(root,val);
        return val[k-1];
    }
};
