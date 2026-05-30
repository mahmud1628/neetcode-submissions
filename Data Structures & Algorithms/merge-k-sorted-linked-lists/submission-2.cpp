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
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto node : lists) {
            if(node)
                pq.push(make_pair(node->val,node));
        }
        if(!pq.size()) return nullptr;

        ListNode * temp = new ListNode(-1);
        ListNode * sorted_list = temp;

        while(pq.size()) {
            temp = temp->next = pq.top().second;
            pq.pop();
            if(temp->next) {
                pq.push(make_pair(temp->next->val,temp->next));
            }
        }
        temp->next = nullptr;

        return sorted_list->next;
    }
};
