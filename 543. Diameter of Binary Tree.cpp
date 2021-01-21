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
    int helper(TreeNode* root,int &diameter){
        if(root==nullptr){
            return 0;
        }
        int leftDepth=helper(root->left,diameter);
        int rightDepth=helper(root->right,diameter);
        diameter=max(diameter,leftDepth+rightDepth);
        return max(leftDepth,rightDepth)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        helper(root,diameter);
        return diameter;
    }
};
