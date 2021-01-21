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
    
    void maxZigZag(TreeNode* root,bool direction,int &count,int currCount){
        if(root==NULL){
            return ;
        }
        count=max(count,currCount);
        if(direction==true){
            if(root->left!=NULL){
                maxZigZag(root->left,false,count,currCount+1);
            }
            if(root->right!=NULL){
                maxZigZag(root->right,true,count,1);
            }
        }
        else{
            if(root->right!=NULL){
                maxZigZag(root->right,true,count,currCount+1);
            }
            if(root->left!=NULL){
                maxZigZag(root->left,false,count,1);
            }
        }
    }
    
    int longestZigZag(TreeNode* root) {
        int count=0;
        maxZigZag(root,true,count,0);
        return count;
    }
};
