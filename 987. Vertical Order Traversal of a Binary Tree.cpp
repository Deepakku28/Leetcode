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
    const static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.first==b.first){
            return (a.second<b.second);
        }
        return (a.first>b.first);
    }
    
    void helper(TreeNode* root,int x,int y,map<int,vector<pair<int,int>>> &mp){
        if(root==NULL){
            return;
        }
        mp[x].push_back({y,root->val});
        helper(root->left,x-1,y-1,mp);
        helper(root->right,x+1,y-1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        helper(root,0,0,mp);
        for(auto it:mp){
            vector<pair<int,int>> temp=it.second;
            sort(temp.begin(),temp.end(),comp);
            vector<int> minAns;
            for(auto itr:temp){
                minAns.push_back(itr.second);
            }
            ans.push_back(minAns);
        }
        return ans;
    }
};
