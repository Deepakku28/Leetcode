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
    void helper(vector<string> &ans,TreeNode* root,string str){
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(str);
            return;
        }
        if(root->left!=nullptr){
            helper(ans,root->left,str+"->"+to_string(root->left->val));
        }
        if(root->right!=nullptr){
            helper(ans,root->right,str+"->"+to_string(root->right->val));
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<string> ans;
        helper(ans,root,to_string(root->val));
        return ans;
    }
};
