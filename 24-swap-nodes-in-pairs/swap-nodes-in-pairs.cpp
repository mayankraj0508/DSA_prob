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
      if(head==NULL|| head->next==NULL){
          return head;
      }
      ListNode*newHead = reverse(head->next);
      head->next->next = head;
      head->next  = NULL;
      return newHead;
  }

    ListNode* swapPairs(ListNode* head) {
        ListNode*ans  = NULL;
      ListNode*prev = NULL;
      ListNode*a = head;
      if(head==NULL || head->next==NULL){
        return head;
      }
      ListNode*b = head->next;
      
      ListNode*nex = b->next;
     while(a){
        // if(prev!=NULL){
        //     prev->next=NULL;
        // }
        b->next = NULL;
       
        if(prev==NULL){
             a = reverse(a);
        ans  = a;
          a->next->next = nex;
          prev = a->next;
          if(nex==NULL){
            break;
          }
          a = nex;
          b = a->next;
          if(b==NULL){
            break;
          }
          nex = b->next;
        }
        else{
            b->next = NULL;
            a = reverse(a);
            prev->next = a;
            prev = a->next;
            if(a->next==NULL){
                break;
            }
            a->next->next = nex;
            if(nex==NULL){
                break;
            }
            a = nex;
            b =a->next;
            if(b==NULL){
                break;
            }
            nex = b->next;
        }
     }
     return ans;
        
    }
};