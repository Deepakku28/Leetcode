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
    int widthOfBinaryTree(TreeNode* root) {
        size_t ans=0;
        if(root==NULL){
            return ans;
        }
        queue<pair<TreeNode*,size_t>> q;
        q.push({root,1});
        while(!q.empty()){
            size_t n=q.size();
            ans=max(ans,q.back().second-q.front().second+1);
            while(n--){
                auto curr=q.front();
                q.pop();
                if(curr.first->left){
                    q.push({curr.first->left,2*curr.second});
                }
                if(curr.first->right){
                    q.push({curr.first->right,2*curr.second+1});
                }
            }
        }
        return ans;
    }
};
