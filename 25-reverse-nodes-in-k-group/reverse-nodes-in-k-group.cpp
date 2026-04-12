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
    // O(n) time, O(1) space
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = & dummy;

        while (true) {
            // Check if k nodes exist
            ListNode* scout = groupPrev;
            for (int i =0; i < k; i++) {
                scout = scout->next;
                if (scout == nullptr) return dummy.next;
            }

            // Reverse k nodes
            ListNode* groupStart = groupPrev->next;
            ListNode* prev = nullptr;
            ListNode* curr = groupStart;
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // prev = new head of reversed group
            // curr = first node of next group
            // groupStart = now the tail of the reversed group
            
            // back into list
            groupStart->next = curr;
            groupPrev->next = prev;

            // advance to next group
            groupPrev = groupStart;
        }
    }
};