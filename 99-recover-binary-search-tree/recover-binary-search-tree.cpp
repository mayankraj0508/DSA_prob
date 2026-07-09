/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     
    void inorder(TreeNode*&root,vector<int>&in){
        if(root==NULL){
            return ;
    }
    inorder(root->left,in);
    in.push_back(root->val);
    inorder(root->right,in);
    }
    void f(TreeNode*&root,int p,int q,TreeNode*&P,TreeNode*&Q){
        if(root==NULL||P!=NULL&&Q!=NULL){
            return ;
        }
        if(root->val==q){
          
            Q = root;
            
        }
        if(root->val==p){
     
            P = root;
            
        }
    
            f(root->left,p,q,P,Q);
             f(root->right,p,q,P,Q);
        

    }
    void recoverTree(TreeNode* root) {
        vector<int>in;
        int p,q;
        inorder(root,in);
     int first = INT_MIN, second = INT_MIN;

for(int i = 1; i < in.size(); i++){
    if(in[i] < in[i-1]){
        if(first ==INT_MIN){
            first = in[i-1];   // first wrong (bada wala)
        }
        second = in[i];        // last wrong (chhota wala)
    }
}

p = second;
q = first;

        TreeNode*P = NULL;
        TreeNode*Q=NULL;
        f(root,p,q,P,Q);
        if(P&&Q){
        swap(P->val,Q->val);
        }

    }
};