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
    void helper(TreeNode* root,long long int &first,long long int &second){
        if(!root){
            return ;
        }
        if(root->val<first){
            second=first;
            first=root->val;
        }
        else if(root->val>first && root->val<second){
            second=root->val;
        }
        helper(root->left,first,second);
        helper(root->right,first,second);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        long long int first=1e15;
        long long int second=1e15;
        if(!root || (!root->left && !root->right)){
            return -1;
        }
        helper(root,first,second);
        return (second==1e15?-1:second);
    }
};
