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
    void helper(TreeNode* root,TreeNode* &curr,TreeNode* &head){
        if(root==NULL){
            return ;
        }
        helper(root->left,curr,head);
        if(head==NULL) { 
            head=new TreeNode(root->val);
            curr=head;
        }
        else{
            curr->right=new TreeNode(root->val);
            curr=curr->right;
        }
        helper(root->right,curr,head);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* curr=NULL;
        TreeNode* head=NULL;
        helper(root,curr,head);
        return head;
    }
};
