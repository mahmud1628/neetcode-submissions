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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        vector<int> v;
        for(auto node : lists) {
            while(node) {
                v.push_back(node->val);
                node = node->next;
            }
        }
        sort(v.begin(),v.end());
        ListNode * sorted_list = new ListNode(v[0]);
        ListNode * temp = sorted_list;
        for(int i = 1;i<v.size();i++) {
            temp = temp->next = new ListNode(v[i]);
        }
        temp->next = nullptr;
        return sorted_list;
    }
};
