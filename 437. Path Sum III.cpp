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
    int helper(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        if(sum==root->val){
            ans++;
        }
        ans+=helper(root->left,sum-root->val);
        ans+=helper(root->right,sum-root->val);
        return ans;
    }
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        int ans=0;
        ans+=helper(root,sum);
        ans+=pathSum(root->left,sum);
        ans+=pathSum(root->right,sum);
        return ans;
    }
};
