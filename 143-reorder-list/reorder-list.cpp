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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;
        while(curr){
            s.push(curr);
            curr = curr->next;
        }
        curr = head;
        unordered_map<ListNode*, bool> vis;
        while(true){
            ListNode* last = s.top();
            s.pop();
            ListNode* next = curr->next;
            vis[curr] = true;
            if(vis[last]){ 
                curr->next = NULL; 
                break; 
            } 
            curr->next = last; 
            vis[last] = true;
            curr = curr->next; 
            if(vis[next]){
                curr->next = NULL;
                break;
            }
            curr->next = next;
            curr = curr->next;
        }
    }
};