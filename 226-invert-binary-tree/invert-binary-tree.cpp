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
    TreeNode*f(TreeNode*root){
        if(root==NULL){
            return NULL;
        }
        TreeNode *root2 = new TreeNode(root->val);
        root2->left = f(root->right);
        root2->right = f(root->left);
        return root2;

    }
    TreeNode* invertTree(TreeNode* root) {
    //     if(root==NULL){
    //         return NULL;
    //     }
    //   swap(root->left,root->right);
    //   invertTree(root->left);
    //   invertTree(root->right);
    //   return root;
       return f(root);
    }
};
