class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Fix 2: Free the memory
            return newHead;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Fix 2: Free the memory
        return head;
    }
};