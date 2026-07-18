/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
          if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // moves 1 step
            fast = fast->next->next;    // moves 2 steps

            if (slow == fast) {
                return true; // they met -> cycle exists
            }
        }

        return false; // fast reached the end -> no cycle
    }
};