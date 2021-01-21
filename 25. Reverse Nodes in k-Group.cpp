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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current=head;
        for(int i=0;i<k;i++){
            if(current==NULL){
                return head;
            }
            current=current->next;
        }
        ListNode* nextPtr=NULL;
        ListNode* newHead=NULL;
        current=head;
        int count=0;
        while(count<k && current!=NULL){
            nextPtr=current->next;
            current->next=newHead;
            newHead=current;
            current=nextPtr;
            count++;
        }
        if(nextPtr!=NULL){
            head->next=reverseKGroup(nextPtr,k);
        }
        return newHead;
    }
};
