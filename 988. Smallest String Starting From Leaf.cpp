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
    void helper(TreeNode* root,string &str,string curr){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            curr=char('a'+root->val)+curr;
            str=min(str,curr);
            return ;
        }
        helper(root->left,str,char('a'+root->val)+curr);
        helper(root->right,str,char('a'+root->val)+curr);
        curr.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string str="~";
        helper(root,str,"");
        return str;
    }
};
