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
    
    int dfs(TreeNode* root,vector<int>& total){
        if(root==NULL){
            return 0;
        }
        else if (root->left==NULL && root->right==NULL){
            int count=0;
            total[root->val]++;
            for(auto it:total){
                if(it%2==1){
                    count++;
                }
            }
            total[root->val]--;
            if(count>1){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            total[root->val]++;
            int ans=dfs(root->left,total)+dfs(root->right,total);
            total[root->val]--;
            return ans;
        }
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> total(10,0);
        return dfs(root,total);
    }
};
