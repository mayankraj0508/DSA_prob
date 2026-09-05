class Solution {
public:
    vector<vector<int>>ans;
    void f(int i, vector<int>&nums,vector<int>&temp, int target){
        if(target==0) {
          ans.push_back(temp);
          return ;

        }
        if(target<0 || i>=nums.size()) return ;
        // take 
        temp.push_back(nums[i]);
        f(i+1,nums,temp,target-nums[i]);
        if(temp.size()) temp.pop_back();
        int idx = i+1;
        while(idx>=1 &&  idx<nums.size() &&nums[idx]==nums[idx-1]){
            idx++;
        }
        f(idx,nums,temp,target);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,candidates,temp,target);
        return ans ;
       
    }
};
