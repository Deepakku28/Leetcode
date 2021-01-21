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
    int helper(TreeNode* root,int &steps){
        if(root==NULL){
            return 0;
        }
        int coin=helper(root->left,steps)+helper(root->right,steps);
        if(root->val==0){
            coin+=-1;
        }
        else{
            coin+=root->val-1;
        }
        steps+=abs(coin);
        return coin;
    }
    
    int distributeCoins(TreeNode* root) {
        int steps=0;
        helper(root,steps);
        return steps;
    }
};
