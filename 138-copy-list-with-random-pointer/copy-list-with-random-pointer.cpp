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
        unordered_map<Node*,Node*>m;
        Node*temp = head;
        while(temp){
            Node*c = new Node(temp->val);
            m[temp] = c;
            temp = temp->next;  
        }
        temp = head;
        Node*dummy  = new Node(-1);
        Node*t  = dummy;
        t->next  = m[head];
        t->random = NULL;
        t  = t->next;
        while(temp){
            t->next = m[temp->next];
            t->random  = m[temp->random];
            t = t->next;
            temp  = temp->next;

        }
        return dummy->next;
    }
};