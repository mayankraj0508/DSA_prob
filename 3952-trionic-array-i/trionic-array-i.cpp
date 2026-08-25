class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        while(i<nums.size()){
            while(i<nums.size() && nums[i]>nums[i-1]){
                i++;
            }
            if(i==1) return false;
            if(i==nums.size()){
                return false;
            }
            while(i<nums.size() && nums[i]<nums[i-1]){
                i++;
            }
            if(i==nums.size()) return false;
            while(i<nums.size() && nums[i]>nums[i-1]){
                i++;
            }
            if(i==nums.size()) return true;
            return false;

        }
        return false;
        
    }
};