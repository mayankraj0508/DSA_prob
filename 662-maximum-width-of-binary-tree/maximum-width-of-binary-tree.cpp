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

   #define pp pair<TreeNode*, long long >
    int widthOfBinaryTree(TreeNode* root) {
        queue<pp>q;
        q.push({root,0});
        int ans  = 0;
        while(q.size()){
            int sz = q.size();
            long long  first  = -1;
            long long  last  = -1;
            long long a = q.front().second;
            for(int i = 0; i<sz; i++){
                TreeNode*temp = q.front().first;
                long long idx = q.front().second-a;
                q.pop();
                if(i==0) first  = idx;
                if(i==sz-1) last  = idx;
                
                if(temp->left){
                    q.push({temp->left,(long long)2*idx});
                }
                if(temp->right){
                    q.push({temp->right,(long long)2*idx+1});
                }
                

            }
            if(first!=-1 && last!=-1)
            ans  = max(ans,(int)(last-first+1));

        }
        return ans ;

        
    }
};