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
    int helper(TreeNode* root,int &maxSum){
        if(root==NULL){
            return 0;
        }
        int leftSum=helper(root->left,maxSum);
        int rightSum=helper(root->right,maxSum);
        maxSum=max(maxSum,root->val+leftSum+rightSum);
        return max(0,root->val+max(leftSum,rightSum));
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};
