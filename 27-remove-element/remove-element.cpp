class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size()-1;
        int last = 0;
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
              if(nums[0]==val){
                return 0;
              }
              else{
                return 1;
              }
        }
        while(i<=j){
            if(nums[i]==val && nums[j]!=val){
                swap(nums[i],nums[j]);
                last = j;
            }
            else if (nums[i]!=val && nums[j]==val){
                 j--;
                 last = j;

            }
            else if(nums[i]==val && nums[j]==val){
                j--;
                last = j;
            }
            else{
                i++;
            }
        }
          cout<<j;
        return j+1;
        
    }
};