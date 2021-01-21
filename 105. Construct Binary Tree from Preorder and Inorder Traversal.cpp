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
    TreeNode* buildTreeUtility(vector<int>& preorder, vector<int>& inorder,int &index,int start,int end){
        if(start>end){
            return NULL;
        }
        int i=start;
        while(inorder[i]!=preorder[index]){
            i++;
        }
        index++;
        TreeNode* temp=new TreeNode(inorder[i]);
        temp->left=buildTreeUtility(preorder,inorder,index,start,i-1);
        temp->right=buildTreeUtility(preorder,inorder,index,i+1,end);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=preorder.size()-1;
        return buildTreeUtility(preorder,inorder,index,0,n);
    }
};
