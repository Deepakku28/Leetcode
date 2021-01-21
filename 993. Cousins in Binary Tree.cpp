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
    void helper(TreeNode * root,int level,int &target,int parent,pair<int,int>& ans) {
        if(root==nullptr){
            return;
        }
        if(root->val==target) {
            ans.first=level;
            ans.second=parent;
            return;
        }
        helper(root->left,level+1,target,root->val,ans);
        helper(root->right,level+1,target,root->val,ans);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> val1,val2;
        helper(root,0,x,-1,val1);
        helper(root,0,y,-1,val2);
        return (val1.first==val2.first && val1.second!=val2.second);
    }
};
