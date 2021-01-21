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
    int getDecimalValue(ListNode* head) {
        vector<int> value;
        while(head!=nullptr){
            value.push_back(head->val);
            head=head->next;
        }
        int base=1;
        int ans=0;
        for(int i=value.size()-1;i>=0;i--){
            ans+=base*value[i];
            base=base*2;
        }
        return ans;
    }
};
