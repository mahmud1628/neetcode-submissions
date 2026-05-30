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
    bool hasCycle(ListNode* head) {
        head->val = 1001;
        while(head->next) {
            if(head->next->val == 1001) return true;
            else {
                head = head->next;
                head->val = 1001;
            }
        }
        return false;
    }
};
