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
    ListNode* helper(ListNode* head) {
        if( head->next == nullptr) return head;
        ListNode * temp = helper(head->next);
        head->next->next = head;
        head->next = nullptr;
        return temp;
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        head = helper(head);
        return head;
    }
};
