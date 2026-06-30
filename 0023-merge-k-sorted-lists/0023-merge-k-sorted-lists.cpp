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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()){
            auto curr = pq.top().second;
            pq.pop();

            if(curr->next) pq.push({curr->next->val, curr->next});
            tail->next = curr;
            tail = tail->next;
        }
        return dummy->next;
        
    }
};