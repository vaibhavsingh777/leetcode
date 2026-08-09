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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) return head;

        int size = 1;
        ListNode dummy(0, head);
        ListNode* temp = dummy.next;

        while(temp->next != nullptr){
            size += 1;
            temp = temp->next;
        }
        k %=size;
        if (k == 0) return head;
        temp->next = head;
        int move = size - k;
        for(int i = 0; i < move-1; i++){
        head = head->next;
        }
        ListNode* newHead = head->next;
        head->next = nullptr;
        return newHead;;
        
    }
};