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
    void reorderList(ListNode* head) {
        vector<ListNode * > v;
        while(head) {
            v.push_back(head);
            head = head->next;
        }
        if(v.size() == 1) return;

        ListNode * head2 = new ListNode(-1);
        ListNode * temp = new ListNode(-1);
        head2 = temp;

        int left = 0, right = v.size() - 1;
        while(true) {
            if(left == right) {
                temp = temp->next = v[left];
                break;
            }
            else if(left > right) {
                break;
            }
            temp = temp->next = v[left];
            temp = temp->next = v[right];
            left++;
            right--;
        }
        temp->next = nullptr;
        head = head2->next;
        
    }
};
