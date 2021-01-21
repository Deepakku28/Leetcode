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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr){
            return head;
        }
        ListNode* start=head;
        ListNode* itr=head->next;
        while(itr!=nullptr){
            if(start->val!=itr->val){
                start=start->next;
                start->val=itr->val;
            }
            itr=itr->next;
        }
        start->next=NULL;
        return head;
    }
};
