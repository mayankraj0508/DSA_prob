class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size()-1;
        int last = 0;
      
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