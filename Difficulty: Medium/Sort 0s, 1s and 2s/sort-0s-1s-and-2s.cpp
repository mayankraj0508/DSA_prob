class Solution {
  public:
    void sort012(vector<int>& nums) {
        int lo = 0;
        int mid = 0;
        int hi = nums.size()-1;
        // o to lo-1 0 
        // lo to mid-1 1 
        //mid- high - 0/1/2
        //high+1 - last 2
        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[lo],nums[mid]);
                    mid++;
                    lo++;
                
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[hi],nums[mid]);
                hi--;
                
            }
            
        }
        
 

        
    }
};