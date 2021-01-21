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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        deque<TreeNode*> q;
        q.push_back(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int> val;
            if(flag==true){
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop_front();
                    val.push_back(curr->val);
                    if(curr->left!=nullptr){
                        q.push_back(curr->left);
                    }
                    if(curr->right!=nullptr){
                        q.push_back(curr->right);
                    }
                }
                ans.push_back(val);
                flag=false;
            }
            else{
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.back();
                    q.pop_back();
                    val.push_back(curr->val);
                    if(curr->right!=nullptr){
                        q.push_front(curr->right);
                    }
                    if(curr->left!=nullptr){
                        q.push_front(curr->left);
                    }
                }
                ans.push_back(val);
                flag=true;
            }
        }
        return ans;
    }
};
