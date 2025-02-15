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
    ListNode* reversell(ListNode*& head) {
        if (!head || !head->next)
            return head;

        ListNode* newHead = reversell(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reversell(slow->next);

        ListNode* first = head;
        ListNode* second = newHead;

        while (second) {
            if (first->val != second->val) {
                reversell(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reversell(newHead);
        return true;
    }
};