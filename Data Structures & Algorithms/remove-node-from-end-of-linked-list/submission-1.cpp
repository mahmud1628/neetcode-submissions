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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode* temp = head;
        while(temp) {
            st1.push(temp);
            temp = temp->next;
        }
        n--;
        while(n--) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.pop();
        while(st1.size()) {
            st2.push(st1.top());
            st1.pop();
        }
        temp = new ListNode(-1);
        head = temp;
        while(st2.size()) {
            temp = temp->next = st2.top();
            st2.pop();
        }
        temp = temp-> next = nullptr;
        return head->next;
    }
};
