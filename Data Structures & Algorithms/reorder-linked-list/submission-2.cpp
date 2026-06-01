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
        vector<ListNode*> v;
        ListNode* temp = head;
        while(temp) {
            v.push_back(temp);
            temp = temp->next;
        }

        temp = new ListNode();
        ListNode* head_r = temp;

        int left = 0, right = v.size() - 1;

        while(left <= right) {
            temp = temp->next = v[left];
            if(left == right) break;
            temp = temp->next = v[right];
            left++;
            right--;
        }
        temp->next = nullptr;
        head = head_r->next;
    }
};
