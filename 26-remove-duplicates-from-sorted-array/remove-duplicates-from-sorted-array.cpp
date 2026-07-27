class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int k = 0;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]==nums[i-1]){
                i++;
            }
            if(i==nums.size()){
                break;
            }
            
            nums[k] = nums[i-1];
            k++;
            i++;
        }
        nums[k] = nums[i-1];
        return k+1;
        
    }
};