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
    ListNode* merge(ListNode* first, ListNode* second) {
        if(!first->next) {
            first->next = second;
            return first;
        }
        ListNode * curr_first = first, * next_first = first->next;
        ListNode * curr_second = second, * next_second = second->next;;
        while(next_first && curr_second) {
            if(curr_second->val >= curr_first->val && curr_second->val <= next_first->val) {
                next_second = curr_second->next;
                curr_first->next = curr_second;
                curr_second->next = next_first;
                curr_first = curr_first->next;
                curr_second = next_second;
            }
            else {
                if(next_first->next) {
                    next_first = next_first->next;
                    curr_first = curr_first->next;
                }
                else {
                    next_first->next = curr_second;
                    break;
                }
            }
        }
        return first;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val < list2->val) {
            return merge(list1,list2);
        }
        else {
            return merge(list2,list1);
        }
    }
};
