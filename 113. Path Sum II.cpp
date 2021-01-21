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
    void dfs(TreeNode* root,vector<vector<int>> &ans,vector<int> &curr,int sum){
        if(root==NULL){
            return;
        }
        curr.push_back(root->val);
        if(sum==root->val && root->left==NULL && root->right==NULL){
            ans.push_back(curr);
        }
        dfs(root->left,ans,curr,sum-root->val);
        dfs(root->right,ans,curr,sum-root->val);
        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(root,ans,curr,sum);
        return ans;
    }
};
