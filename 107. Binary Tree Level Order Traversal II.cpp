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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> curr;
            int len=q.size();
            for(int i=0;i<len;i++){
                TreeNode* currNode=q.front();
                q.pop();
                curr.push_back(currNode->val);
                if(currNode->left!=nullptr){
                    q.push(currNode->left);
                }
                if(currNode->right!=nullptr){
                    q.push(currNode->right);
                }
            }
            ans.push_back(curr);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
