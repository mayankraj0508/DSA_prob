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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        while(q.size()){
            int sz = q.size();
            for(int i = 0;i<sz; i++){
            TreeNode*temp = q.front();
            q.pop();
            if(temp && i==0)
            ans.push_back(temp->val);
            if(temp->right){
                q.push(temp->right);
            }
            
            if(temp->left)
            q.push(temp->left);
            
        }

        }
        return ans ;
    }
};