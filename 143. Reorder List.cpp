/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* &fast){
        ListNode* nextPtr=NULL;
        ListNode* newHead=NULL;
        while(fast!=NULL){
            nextPtr=fast->next;
            fast->next=newHead;
            newHead=fast;
            fast=nextPtr;
        }
        fast=newHead;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return ;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            if(fast->next!=NULL){
                fast=fast->next->next;
            }
        }
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        reverse(fast);
        ListNode* ptr=new ListNode(0);
        head=ptr;
        while(slow!=NULL || fast!=NULL){
            if(slow!=NULL){
                ptr->next=slow;
                slow=slow->next;
                ptr=ptr->next;
            }
            if(fast!=NULL){
                ptr->next=fast;
                fast=fast->next;
                ptr=ptr->next;
            }
        }
        ptr=NULL;
        head=head->next;
    }
};
