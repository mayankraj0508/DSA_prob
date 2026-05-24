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
    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*newhead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*rev1 = reverse(l1);
        ListNode*rev2 = reverse(l2);
        ListNode*temp1 = rev1;
        ListNode*temp2  = rev2;
        int carry = 0;
        ListNode*c = new ListNode(100);
        ListNode*tempc = c;
        while(temp1 && temp2){
            int  v = temp1->val+temp2->val+carry;
            if(v<10){
                ListNode*d = new ListNode(v);
                tempc->next = d;
                carry = 0;
                temp1 = temp1->next;
                temp2 = temp2->next;
                tempc = tempc->next;
            }
            else{
                carry = v/10;
                v = v%10;
                ListNode*p = new ListNode(v);
                tempc->next = p;
                temp1 = temp1->next;
                temp2 = temp2->next;
                tempc = tempc->next;
            }
        }
        while(temp1){
            int v = temp1->val+carry;
            if(v<10){
                ListNode*d = new ListNode(v);
                tempc->next = d;
                carry = 0;
                temp1 = temp1->next;
                tempc = tempc->next;
            }
            else{
                carry = v/10;
                v = v%10;
                ListNode*p = new ListNode(v);
                tempc->next = p;
                temp1 = temp1->next;
                tempc = tempc->next;
            }

        }
             while(temp2){
            int v = temp2->val+carry;
            if(v<10){
                ListNode*d = new ListNode(v);
                tempc->next = d;
                carry = 0;
                tempc = tempc->next;
                temp2 = temp2->next;
            }
            else{
                carry = v/10;
                v = v%10;
                ListNode*p = new ListNode(v);
                tempc->next = p;
                temp2 = temp2->next;
                tempc = tempc->next;
            }

        }
        if(carry!=0){
            ListNode*n = new ListNode(carry);
            tempc->next = n;
            tempc = tempc->next;
        }
        c = reverse(c->next);
        return c ;

        
    }
};