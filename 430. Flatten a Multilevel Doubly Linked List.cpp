/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp->child!=NULL){
                Node* Next=temp->next;
                Node* Child=flatten(temp->child);
                temp->child=NULL;
                temp->next=Child;
                Child->prev=temp;
                Node* last=Child;
                while(last->next!=NULL){
                    last=last->next;
                }
                last->next=Next;
                if(Next!=NULL){
                    Next->prev=last;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};
