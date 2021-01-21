class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead=nullptr;
        ListNode* nextPtr=nullptr;
        while(head!=nullptr){
            nextPtr=head->next;
            head->next=newHead;
            newHead=head;
            head=nextPtr;
        }
        return newHead;
    }
};
