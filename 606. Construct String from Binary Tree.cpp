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
    void preorder(TreeNode* t,string &str){
        if(t==NULL){
            return ;
        }
        str+=to_string(t->val);
        if(t->left){
            str+='(';
            preorder(t->left,str);
            str+=')';
        }
        if(t->right){
            if(t->left==NULL){
                str+="()";
            }
            str+='(';
            preorder(t->right,str);
            str+=')';
        }
    }
    
    string tree2str(TreeNode* t) {
        string str="";
        preorder(t,str);
        return str;
    }
};
