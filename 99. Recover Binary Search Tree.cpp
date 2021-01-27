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
    void helper(TreeNode* root,TreeNode* &prev,TreeNode* &start,TreeNode* &middle,TreeNode* &end){
        if(root==NULL){
            return;
        }
        helper(root->left,prev,start,middle,end);
        if(prev!=NULL && root->val<prev->val){
            if(start==NULL){
                start=prev;
                middle=root;
            }
            else{
                end=root;
            }
        }
        prev=root;
        helper(root->right,prev,start,middle,end);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* start=NULL;
        TreeNode* middle=NULL;
        TreeNode* end=NULL;
        helper(root,prev,start,middle,end);
        if(start!=NULL && end!=NULL){
            swap(start->val,end->val);
        }
        else if(start!=NULL && middle!=NULL){
            swap(start->val,middle->val);
        }
    }
};
