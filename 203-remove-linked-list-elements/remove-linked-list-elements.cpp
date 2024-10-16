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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head -> val == val){
            head = head -> next;
        }
        if(head == nullptr)
            return head;
        ListNode * p{head}, *q{head -> next};
        while(q!=nullptr){
            if(q->val == val){
                p->next = q ->next;
                q = p->next;
            }
            else{
            p = p->next; 
            q = p -> next;
            }
        }
    return head;
    }
};