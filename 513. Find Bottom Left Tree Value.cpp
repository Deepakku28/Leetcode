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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> ans;
        ans.push_back(root);
        while(!q.empty()){
            vector<TreeNode*> temp;
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    temp.push_back(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                    temp.push_back(curr->right);
                }
            }
            ans=temp;
        }
        return ans[0]->val;
    }
};
