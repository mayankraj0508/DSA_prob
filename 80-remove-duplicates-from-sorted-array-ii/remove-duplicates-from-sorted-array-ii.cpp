class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;// pointer pointing array 
        int i = 1;
        if(nums.size()==1){
            return 1;
        }
        while(i<nums.size()){
          int count  = 1;
          int k = nums[i-1];
          while(i<nums.size() && nums[i]==nums[i-1]){
            count++;
            i++;

          }
          if(count>2){
               count  = 2;
              while(count-- && idx<nums.size()){
                nums[idx] = k;
                idx++;
            }
          }
          else{
            while(count-- && idx<nums.size()){
                nums[idx] = k;
                idx++;
            }
          }
          i++;



        }
        if(nums.size()>1){
            if(nums[nums.size()-1]!=nums[nums.size()-2]){
                nums[idx] = nums[nums.size()-1];
                idx++;
            }
        }
        return idx;







        
    }
};