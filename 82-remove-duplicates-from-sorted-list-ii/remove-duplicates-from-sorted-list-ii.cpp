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
private:
    bool shouldDelete(ListNode* node) {
        return node->val == node->next->val;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (shouldDelete(curr)) {
                while (curr->next && shouldDelete(curr)) {
                    curr = curr->next;
                }
                prev->next = curr->next;
            } else {
                prev = prev->next; // move to next distinct node
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};