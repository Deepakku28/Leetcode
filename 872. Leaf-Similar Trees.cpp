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
    void inorder(TreeNode *root,vector<int> &val){
        if(root==NULL){
            return ;
        }
        inorder(root->left,val);
        if(root->left==NULL && root->right==NULL){
            val.push_back(root->val);
        }
        inorder(root->right,val);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val1;
        vector<int> val2;
        inorder(root1,val1);
        inorder(root2,val2);
        if(val1.size()!=val2.size()){
            return false;
        }
        for(int i=0;i<val1.size();i++){
            if(val1[i]!=val2[i]){
                return false;
            }
        }
        return true;
    }
};
