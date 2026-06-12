class Solution {
public:
    int f(vector<int>&nums, int k){
        if(k<0){
            return 0;
        }
         int i = 0;
        int j = 0;
        int count = 0;
        int  sum = 0;
      
        while(i<nums.size() && j<nums.size()){
              sum  = sum + nums[j];
                while(sum>k && i<nums.size()){
                    sum  = sum - nums[i];
                    i++;
                }
                if(sum<=k){
                     count = count + j-i+1;
                }
          j++;
            
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    
        return f(nums,goal)-f(nums,goal-1);
    }
};