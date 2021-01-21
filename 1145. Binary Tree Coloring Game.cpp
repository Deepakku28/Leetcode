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
    void find(TreeNode* root,int &x,TreeNode* &temp){
        if(root==NULL){
            return ;
        }
        if(root->val==x){
            temp=root;
            return ;
        }
        find(root->left,x,temp);
        find(root->right,x,temp);
    }
    
    int count(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+count(root->left)+count(root->right);
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* temp=NULL;
        find(root,x,temp);
        int countLeft=count(temp->left);
        int countRight=count(temp->right);
        //cout<<countLeft<<" "<<countRight<<endl;
        int remain=n-countLeft-countRight-1;
        if(countLeft>countRight+remain || countRight>countLeft+remain || remain>countLeft+countRight){
            return true;
        }
        return false;
    }
};
