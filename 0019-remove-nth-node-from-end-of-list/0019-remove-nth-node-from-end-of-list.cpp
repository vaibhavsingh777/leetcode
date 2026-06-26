class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        
        // Pass 1: Count total nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
        // Edge Case: If we need to remove the head node
        if (count == n) {
            ListNode* newHead = head->next;
            delete head; // Free memory
            return newHead;
        }
        
        // Pass 2: Find the node *just before* the one to remove
        ListNode* temp1 = head;
        // Loop runs (count - n - 1) times to stop right before the target
        for (int i = 1; i < count - n; i++) {
            temp1 = temp1->next;
        }
        
        // Save the node to delete, bridge the gap, then free memory
        ListNode* nodeToDelete = temp1->next;
        temp1->next = temp1->next->next;
        delete nodeToDelete;
        
        return head;
    }
};