class Solution {
public:
    void f(vector<int>&nums,vector<vector<int>>&ans,int i){
      if(i==nums.size()-1){
        ans.push_back(nums);
        return ;
      }
      
      unordered_set<int>visited;
      for(int idx = i; idx<nums.size(); idx++){
        if(visited.find(nums[idx])!=visited.end()){
            continue;
        }
        visited.insert(nums[idx]);
         swap(nums[idx],nums[i]);
         f(nums,ans,i+1);
         swap(nums[idx],nums[i]);
      }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,ans,0);
        return ans;
        
        
    }
};