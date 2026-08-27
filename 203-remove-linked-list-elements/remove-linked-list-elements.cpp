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
        while(head && head->val==val){
            head = head->next;
        }
        ListNode*a = head;
        if(head==NULL) return head;
        ListNode*t = head->next;
        if(t==NULL) return head;
        while(a){
            t = a->next;
           while(t && t->val==val){
              t=t->next;
           }
           a->next  = t;
           a = t;

        }
        return head;
        
    }
};