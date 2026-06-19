class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            if(nums[i]<=0){
                nums[i] = INT_MAX;
            }
        }    
        for(int i =0; i<nums.size(); i++){
            if(nums[i]==INT_MAX || nums[i]==INT_MIN ){
                continue;
            }
            int x = abs(nums[i])-1;
            if(x>=nums.size() || x<0){
                continue;
            }
            else{
                if(nums[x]==INT_MAX){
                    nums[x] = INT_MIN;
                }
                else if(nums[x]<0){
                    continue;
                }
               else{
                  nums[x] = -nums[x];

               }

            }
        }  
        for(int i =0;  i<nums.size(); i++){
            if(nums[i]>0 ){
                return i+1;
            }
        } 
        return nums.size()+1;
    }
};