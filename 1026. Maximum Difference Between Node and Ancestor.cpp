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
    int solution(TreeNode* root,int maxVal,int minVal){
        if(root==NULL){
            return (maxVal-minVal);
        }
        return max(solution(root->left,max(root->val,maxVal),min(root->val,minVal)),solution(root->right,max(root->val,maxVal),min(root->val,minVal)));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return solution(root,0,100001);
    }
};
