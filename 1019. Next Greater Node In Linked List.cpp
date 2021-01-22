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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[i]>=s.top()){
                s.pop();
            }
            if(s.empty()){
                ans[i]=0;
            }
            else{
                ans[i]=s.top();
            }
            s.push(arr[i]);
        }
        return ans;
    }
};
