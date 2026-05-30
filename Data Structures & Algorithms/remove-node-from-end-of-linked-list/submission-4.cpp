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
        ListNode* temp = head;
        while(temp) {
            st1.push(temp);
            temp = temp->next;
        }
        if(st1.size() == 1) return nullptr;
        if(st1.size() == n) {
            return head->next;
        }
        n--;
        while(n--) {
            temp = st1.top();
            st1.pop();
        }
        st1.pop();
        if(st1.size())
            st1.top()->next = temp;
        return head;
    }
};
