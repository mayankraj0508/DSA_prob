/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void f(Node*root){
       queue<Node*>q;
       q.push(root);
       while(q.size()){
        int sz = q.size();
         Node*temp = q.front();
         if(temp->left){
            q.push(temp->left);
         }
         if(temp->right){
            q.push(temp->right);
         }
         q.pop();
        for(int i =0; i<sz-1;  i++){
            Node*b = q.front();
            q.pop();
            temp->next = b;
            temp = temp->next;
            if(b->left){
                q.push(b->left);
                
            }
            if(b->right){
                q.push(b->right);
            }
        }
       }
    }
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        f(root);
        return root;

        
        
    }
};