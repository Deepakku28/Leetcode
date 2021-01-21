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
    int check(TreeNode* root,bool& flag){
        if(root==nullptr){
            return 0;
        }
        int L=check(root->left,flag)+1;
        int R=check(root->right,flag)+1;
        if(abs(L-R)>1){
            flag=false;
        }
        return max(L,R);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        bool flag=true;
        check(root,flag);
        return flag;
    }
};
