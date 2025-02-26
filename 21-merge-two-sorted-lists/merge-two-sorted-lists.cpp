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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1 = list1, *t2 = list2;
        ListNode* dummyNode = new ListNode(-1); // Dummy node to simplify code
        ListNode* temp = dummyNode; // Pointer to temp node in the merged list

        // Merge lists until one of them becomes empty
        while (t1 && t2) {
            if (t1->val < t2->val) {
                temp->next = t1; // Attach smaller node to the merged list
                t1 = t1->next;   // Move to the next node in t1
            } else {
                temp->next = t2; // Attach smaller node to the merged list
                t2 = t2->next;   // Move to the next node in t2
            }
            temp = temp->next; // Move to the next node in the merged list
        }

        // Attach the remaining nodes of the non-empty list
        temp->next = t1 ? t1 : t2;

        return dummyNode->next; // Return the head of the merged list
    }
};
