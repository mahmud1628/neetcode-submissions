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
        stack<ListNode*> st;
        ListNode* temp = head;
        while(temp) {
            st.push(temp);
            temp = temp->next;
        }
        if(st.size() == 1) return nullptr;
        if(st.size() == n) {
            return head->next;
        }
        n--;
        while(n--) {
            temp = st.top();
            st.pop();
        }
        st.pop();
        st.top()->next = temp;
        return head;
    }
};
