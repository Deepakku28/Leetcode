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
    bool checkIsSymmetric(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr && root2==nullptr){
            return true;
        }
        if(root1!=nullptr && root2!=nullptr && root1->val==root2->val){
            return (checkIsSymmetric(root1->left,root2->right) && checkIsSymmetric(root1->right,root2->left));
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return checkIsSymmetric(root->left,root->right);
    }
};
