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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if((int)nums.size()==0){
            return NULL;
        }
        auto index=max_element(nums.begin(),nums.end());
        TreeNode* root=new TreeNode(*index);
        vector<int> Left(nums.begin(),index);
        vector<int> Right(index+1,nums.end());
        root->left=constructMaximumBinaryTree(Left);
        root->right=constructMaximumBinaryTree(Right);
        return root;
    }
};
