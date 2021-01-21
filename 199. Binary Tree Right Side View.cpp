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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*,int> curr=q.front();
            q.pop();
            if(curr.first!=NULL){
                if(curr.second>=ans.size()){
                    ans.push_back(curr.first->val);
                }
                q.push(make_pair(curr.first->right,curr.second+1));
                q.push(make_pair(curr.first->left,curr.second+1));
            }
        }
        return ans;
    }
};
