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
    struct cmp {
        bool operator()(Node*a, Node*b){
            return a->data>b->data;
        }
    };
   
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        priority_queue<Node*,vector<Node*>,cmp>pq;
        for(int i = 0; i<arr.size(); i++){
            pq.push(arr[i]);
            
        }
        Node*ans  = new Node(-2);
        Node*temp = ans ;
        while(pq.size()){
            Node*p = pq.top();
            pq.pop();
            if(p==NULL) continue;
            temp->next  = p;
            Node*c = NULL;
            if(p){
             c = p->next;
            p->next  = NULL;
            }
            if(c){
                pq.push(c);
            }
            temp = temp->next;
            
            
        }
        return ans->next;
      
        
    }
};