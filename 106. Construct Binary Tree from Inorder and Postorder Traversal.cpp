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
    int findIndex(vector<int> &inorder,int left,int right,int value){
        for(int i=left;i<=right;i++){
            if(inorder[i]==value){
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* helper(int left,int right,vector<int> &inorder,int &ind,vector<int> &postorder){
        if(left>right || ind<0){
            return NULL;
        }
        int value=postorder[ind--];
        int index=findIndex(inorder,left,right,value);
        TreeNode* root=new TreeNode(value);
        root->right=helper(index+1,right,inorder,ind,postorder);
        root->left=helper(left,index-1,inorder,ind,postorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int left=0;
        int right=inorder.size()-1;
        int ind=postorder.size()-1;
        return helper(left,right,inorder,ind,postorder);
    }
};
