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
    TreeNode* helper(vector<int> &preorder,int &n,int &index,int maxValue){
        if(index>=n || preorder[index]>maxValue){
            return NULL;
        }
        int value=preorder[index++];
        TreeNode* root=new TreeNode(value);
        root->left=helper(preorder,n,index,value);
        root->right=helper(preorder,n,index,maxValue);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        int n=preorder.size();
        return helper(preorder,n,index,INT_MAX);
    }
};
