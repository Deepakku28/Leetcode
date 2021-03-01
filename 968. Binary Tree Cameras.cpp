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
    int helper(TreeNode* root,int &camera){
        if(root==NULL){
            return 0;
        }
        int leftSide=helper(root->left,camera);
        int rightSide=helper(root->right,camera);
        if(leftSide==-1 || rightSide==-1){
            camera++;
            return 1;
        }
        else if(leftSide==1 || rightSide==1){
            return 0;
        }
        else{
            return -1;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        int camera=0;
        int value=helper(root,camera);
        if(value==-1){
            camera++;
        }
        return camera;
    }
};
