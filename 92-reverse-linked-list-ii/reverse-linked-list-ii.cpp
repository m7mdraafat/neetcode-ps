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
    void reverseSublist(ListNode* nodeBeforeZone, ListNode* zoneStart, int count) {
        ListNode* previous = nullptr;
        ListNode* current = zoneStart;

        for (int i = 0; i < count; i++) {
            ListNode* nextNode = current->next;
            current->next = previous; // 2 -> nullptr
            previous = current; // 2
            current = nextNode;
        }

        // after loop:
        // previous = new head of reversed segment
        // current = first node AFTER the reversed segment
        ListNode* zoneTail = nodeBeforeZone->next; // original zoneStart -> now tail
        zoneTail->next = current; // tail connects to rest of the list
        nodeBeforeZone->next = previous; // splice reversed head in
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* nodeBeforeZone = dummy;

        for (int i = 0; i < left - 1; i++) {
            nodeBeforeZone = nodeBeforeZone->next;
        }

        ListNode* zoneStart = nodeBeforeZone->next;
        reverseSublist(nodeBeforeZone, zoneStart, right - left + 1);

        return dummy->next;
    }
};