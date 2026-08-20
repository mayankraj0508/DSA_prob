class Solution {
  public:
    bool f(vector<int>&nums, int i, int sum ){
        if(sum==0) return true;
        if(sum<0) return false;
        if(i>=nums.size()) return false;
        bool ans ;
        ans  = f(nums,i+1,sum-nums[i])||f(nums,i+1,sum);
        if(ans) return true;
        return false;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        bool ans  = f(arr,0,sum);
        return ans ;
        // code here
        
    }
};