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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(),G.end());
        int count=0;
        while(head){
            if(s.find(head->val)!=s.end() && (head->next==NULL || s.find(head->next->val)==s.end())){
                count++;
            }
            head=head->next;
        }
        return count;
    }
};
