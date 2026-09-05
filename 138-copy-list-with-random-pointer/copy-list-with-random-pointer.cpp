/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // part 1  attaching duplicated nodes tob current ndoes

        Node*temp = head;
        while(temp){
            Node*c = temp->next;
            Node*p = new Node(temp->val);
            temp->next  = p;
            p->next  = c;
            temp = c;

        }
        // assigning the random pointers 
        temp = head;
        while(temp && temp->next ){
            if(temp->random==NULL) temp->next->random  = NULL;
            else
            temp->next->random  = temp->random->next;
          
            temp = temp->next->next;
        }

        // create a dummy node and make copies of it 
        Node*dummy  = new Node(-1);
        Node*t  = dummy;
        temp = head;
        while(temp){
            t->next = temp->next;
            if(temp->next)
            temp->next  = temp->next->next;
            temp = temp->next;
            t = t->next;
        }
        return dummy->next;
      
    }
};