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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int maxVal=INT_MIN;
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    maxVal=max(maxVal,curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    maxVal=max(maxVal,curr->right->val);
                }
            }
            ans.push_back(maxVal);
        }
        ans.pop_back();
        return ans;
    }
};
