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
        vector<ListNode*> v;
        while(head) {
            v.push_back(head);
            head = head->next;
        }
        if(v.size() == 1) return nullptr;
        if(v.size() == n) return v[1];
        v[v.size()-1-n]->next = v[v.size()-n]->next;
        return v[0];
    }
};
