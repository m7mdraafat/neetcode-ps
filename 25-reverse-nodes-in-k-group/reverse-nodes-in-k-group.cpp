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
    // O(n) time, O(n/k) recursion stack depth
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) return head; // fewer thank k nodes left, don't reverse (base case)
            cursor = cursor->next;
        }

        // cursor now is k + 1 node (first node of the second group)
        ListNode* curr = head; // first node of the next group
        ListNode* prev = nullptr; // new head of reversed group
        ListNode* nxt = nullptr; 

        // reverse current group
        for (int i = 0; i < k; i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k); // head is now the tail of reversed group map to the new head of next group.
        return prev;
    }
};