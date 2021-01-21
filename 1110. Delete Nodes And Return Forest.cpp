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
    bool helper(TreeNode* root,unordered_set<int> &s,vector<TreeNode*> &ans){
        if(root==NULL || s.empty()){
            return false;
        }
        if(helper(root->left,s,ans)==true){
            root->left=NULL;
        }
        if(helper(root->right,s,ans)==true){
            root->right=NULL;
        }
        if(s.find(root->val)!=s.end()){
            if(root->left!=NULL && s.find(root->left->val)==s.end()){
                ans.push_back(root->left);
            }
            if(root->right!=NULL && s.find(root->right->val)==s.end()){
                ans.push_back(root->right);
            }
            return true;
        }
        return false;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        if(s.find(root->val)==s.end()){
            ans.push_back(root);
        }
        helper(root,s,ans);
        return ans;
    }
};
