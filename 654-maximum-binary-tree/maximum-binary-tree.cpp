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
    int find(vector<int>&nums, int i, int j){
        int ans  = -1;
        for(int k =i; k<=j; k++){
            ans  = max(ans,nums[k]);

        }
        return ans ;
    }
   TreeNode*f(vector<int>&nums,unordered_map<int,int>&m, int start, int end){
      if(start>end || start<0||end<0||start>=nums.size() || end>=nums.size()){
        return NULL;
      }
      int mx = find(nums,start,end);
      int idx = m[mx];
      TreeNode*root = new TreeNode(mx);
      root->left = f(nums,m,start,idx-1);
      root->right = f(nums,m,idx+1,end);
      return root ;
   }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]] = i;
        }
        int start   = 0;
        int end  = nums.size()-1;
        return f(nums,m,start,end);
    }
};