/* Linked List Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node*merge(Node*a, Node*b){
        if(b==NULL){
            return a;
        }
        Node*d = new Node(-1);
        Node*temp = d;
        Node*ta = a;
        Node*tb = b;
        while(ta && tb){
            if(ta->data<tb->data){
                temp->next  = ta;
                ta  = ta->next;
                temp = temp->next;
            }
            else{
                temp->next  = tb;
                tb  = tb->next;
                temp = temp->next;
            }
        }
        if(ta){
            temp->next  = ta;
        }
        if(tb){
            temp->next  = tb;
        }
        return d->next;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        Node*t  = NULL;
        for(int i = 0; i<arr.size(); i++){
            t = merge(arr[i],t);
        }
        return t;
        
    }
};