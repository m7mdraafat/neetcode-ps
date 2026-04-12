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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        for (int i = 0; i < k; i++) {
            if (cursor == nullptr) return head;
            cursor = cursor->next;
        }

        // cursor now is k + 1 node (first node of the second group)
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        // reverse current group
        for (int i = 0; i < k; i++) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // link tail of current group to the new head of next group
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};