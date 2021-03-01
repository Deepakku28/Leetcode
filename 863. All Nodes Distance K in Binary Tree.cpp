/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root,int &K,vector<int> &ans,int dist){
        if(root==NULL){
            return;
        }
        if(dist==K){
            ans.push_back(root->val);
            return;
        }
        helper(root->left,K,ans,dist+1);
        helper(root->right,K,ans,dist+1);
    }
    
    int findNode(TreeNode* root,TreeNode* target,int &K,vector<int> &ans){
        if(root==NULL){
            return -1;
        }
        if(root==target){
            helper(root,K,ans,0);
            return 1;
        }
        else{
            int leftSide=findNode(root->left,target,K,ans);
            if(leftSide!=-1){
                if(leftSide==K){
                    ans.push_back(root->val);
                    return -1;
                }
                else{
                    helper(root->right,K,ans,leftSide+1);
                    return leftSide+1;
                }
            }
            int rightSide=findNode(root->right,target,K,ans);
            if(rightSide!=-1){
                if(rightSide==K){
                    ans.push_back(root->val);
                    return -1;
                }
                else{
                    helper(root->left,K,ans,rightSide+1);
                    return rightSide+1;
                }
            }
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        findNode(root,target,K,ans);
        return ans;
    }
};
