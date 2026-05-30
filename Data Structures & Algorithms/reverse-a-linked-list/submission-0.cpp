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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        stack<ListNode*> st;
        ListNode * temp = head;
        while(temp->next != nullptr) {
            st.push(temp);
            temp = temp->next;
        }
        head = temp;
        while(!st.empty()) {
            temp = temp->next = st.top();
            st.pop();
        }
        temp->next = nullptr;
        return head;
    }
};
