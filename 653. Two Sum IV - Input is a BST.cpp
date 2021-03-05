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
    void helper(Node* root,vector<int> &arr){
        if(!root){
            return;
        }
        helper(root->left,val);
        arr.push_back(root->val);
        helper(root->right,val);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        helper(root,arr);
        int start=0;
        int end=arr.size()-1;
        while(start<end){
            int sum=arr[start]+arr[end];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
    }
};
