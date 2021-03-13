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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        int len=right-left+1;
        while(left>1){
            prev=curr;
            curr=curr->next;
            left--;
        }
        ListNode* last=prev;
        ListNode* tail=curr;
        ListNode* nextPtr=NULL;
        while(len){
            nextPtr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextPtr;
            len--;
        }
        if(last){
            last->next=prev;
        }
        tail->next=curr;
        return last?head:prev;
    }
};
