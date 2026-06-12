class Solution {
public:
    int f(vector<int>&nums, int k){
        int ans = 0;
         int count = 0;
        int i =0; 
        int j = 0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]%2!=0){
                count++;
            }
            while(count>k  && i<nums.size()){
                if(nums[i]%2!=0){
                    count--;
                }
                i++;

            }
           if(count<=k){
              ans = ans + j-i+1;
           }
           j++;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return f(nums,k)-f(nums,k-1);
        
    }
};