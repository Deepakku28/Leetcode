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
    bool helper(TreeNode* root,int &value){
        if(!root){
            return true;
        }
        return (root->val==value && helper(root->left,value) && helper(root->right,value));
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(!root){
            return true;
        }
        int value=root->val;
        return (helper(root->left,value) && helper(root->right,value));
    }
};
