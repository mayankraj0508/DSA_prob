class Solution {
public:
    int hIndex(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       
       int ans  = 0;
       for(int i = 0; i<nums.size(); i++){
        int rem  = nums.size()-i;
        if(rem<=nums[i]){
            ans  = max(ans,rem);
        }
       }
       return ans ;

        
    }
};