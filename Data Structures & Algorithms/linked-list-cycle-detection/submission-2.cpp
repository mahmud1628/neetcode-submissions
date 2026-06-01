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
        set<ListNode*> s;
        s.insert(head);

        while(head) {
            if(s.find(head->next) == s.end()) s.insert(head->next);
            else return true;

            head = head->next;
        }

        return false;
    }
};
