class Solution {
public:
    bool canJump(vector<int>& nums) {
        int  mxind = 0;
        if(nums.size()==1){
            return true;
        }
        for(int i=0; i<nums.size(); i++){
          if(i<nums.size()-1 && i==mxind && nums[i]==0){
                return false;
            }
            mxind = max(mxind,i+nums[i]);
              
        }
        if(mxind>=nums.size()-1)
            return true; 
            else{
 return false;
        
            }
           
    }
};