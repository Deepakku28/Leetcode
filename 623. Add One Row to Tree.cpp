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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root==NULL){
            return root;
        }
        if(d==1){
            TreeNode* temp=new TreeNode(v);
            temp->left=root;
            return temp;
        }
        queue<TreeNode*> q;
        q.push(root);
        int steps=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(steps==d-1){
                    TreeNode* newLeft=new TreeNode(v);
                    TreeNode* newRight=new TreeNode(v);
                    newLeft->left=curr->left;
                    newRight->right=curr->right;
                    curr->left=newLeft;
                    curr->right=newRight;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            steps++;
        }
        return root;
    }
};
