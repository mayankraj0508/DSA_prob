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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
      
        int level  = 0;

        while(q.size()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
            TreeNode*temp = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            m[c].push_back({r,temp->val});
            if(temp->left){
                q.push({temp->left,{r+1,c-1}});
            }
            if(temp->right){
                q.push({temp->right,{r+1,c+1}});
            }
        }
        level++;

        }
        vector<vector<int>>ans;
        
        for(auto x:m){
            sort(x.second.begin(),x.second.end());
            vector<int>temp;
            for(auto y:x.second){
                temp.push_back(y.second);
            }
            ans.push_back(temp);
        }
         return ans ;

        
    }
};