/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyUtil(Node* head,map<Node*,Node*> &mp){
        if(head==NULL){
            return NULL;
        }
        if(mp.find(head)!=mp.end()){
            return mp[head];
        }
        else{
            Node* newHead=new Node(head->val);
            mp[head]=newHead;
            newHead->next=copyUtil(head->next,mp);
            newHead->random=copyUtil(head->random,mp);
            return newHead;
        }
    }
    
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> mp;
        return copyUtil(head,mp);
    }
};
