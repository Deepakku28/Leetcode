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
    void helper(TreeNode* root,int &minDiff,int &prev){
        if(root==nullptr){
            return;
        }
        helper(root->left,minDiff,prev);
        minDiff=min(minDiff,abs(prev-root->val));
        prev=root->val;
        helper(root->right,minDiff,prev);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int minDiff=INT_MAX;
        int prev=INT_MAX;
        helper(root,minDiff,prev);
        return minDiff;
    }
};
