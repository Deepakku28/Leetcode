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
    void helper(TreeNode* root,int &totalSum,int currSum){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            currSum=currSum*2+root->val;
            totalSum+=currSum;
            return;
        }
        helper(root->left,totalSum,currSum*2+root->val);
        helper(root->right,totalSum,currSum*2+root->val);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int totalSum=0;
        helper(root,totalSum,0);
        return totalSum;
    }
};
