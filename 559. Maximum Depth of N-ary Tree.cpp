/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int steps=0;
        if(root==NULL){
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node* curr=q.front();
                q.pop();
                for(int i=0;i<curr->children.size();i++){
                    q.push(curr->children[i]);
                }
            }
            steps++;
        }
        return steps;
    }
};
