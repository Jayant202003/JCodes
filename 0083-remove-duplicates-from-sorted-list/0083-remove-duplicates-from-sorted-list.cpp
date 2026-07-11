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
    ListNode* deleteDuplicates(ListNode* head) {
         if (!head) return head;
        
        ListNode* current = head;
        
        while (current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate; // free memory (optional in LeetCode, good practice)
            } else {
                current = current->next;
            }
        }
        
        return head;
        
    }
};