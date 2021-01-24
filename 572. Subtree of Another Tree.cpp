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
    bool helper(TreeNode* s, TreeNode* t){
        if(s==NULL && t==NULL){
            return true;
        }
        if(s==NULL || t==NULL){
            return false;
        }
        return (s->val==t->val && helper(s->left,t->left) && helper(s->right,t->right));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return (s!=NULL && helper(s,t) || (s!=NULL && isSubtree(s->left,t)) || (s!=NULL && isSubtree(s->right,t)));
    }
};
