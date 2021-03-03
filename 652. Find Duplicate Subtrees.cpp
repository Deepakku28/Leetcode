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
    string helper(TreeNode* root,unordered_map<string,int> &mp,vector<TreeNode*> &ans){
        if(root==NULL){
            return "";
        }
        string str="("+helper(root->left,mp,ans)+to_string(root->val)+helper(root->right,mp,ans)+")";
        mp[str]++;
        if(mp[str]==2){
            ans.push_back(root);
        }
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> mp;
        helper(root,mp,ans);
        return ans;
    }
};
