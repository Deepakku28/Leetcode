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
    int dfs(TreeNode* root,int &maxLen){
        if(root==NULL){
            return 0;
        }
        int leftSide=dfs(root->left,maxLen);
        int rightSide=dfs(root->right,maxLen);
        if(root->left==NULL || root->left->val!=root->val){
            leftSide=0;
        }
        if(root->right==NULL || root->right->val!=root->val){
            rightSide=0;
        }
        maxLen=max(maxLen,leftSide+rightSide);
        return 1+max(leftSide,rightSide);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int maxLen=0;
        dfs(root,maxLen);
        return maxLen;
    }
};
