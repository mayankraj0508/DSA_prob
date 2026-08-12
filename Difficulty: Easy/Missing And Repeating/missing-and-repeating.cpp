class Solution {
public:
    vector<int> findTwoElement(vector<int>& nums) {
        int an = -1;

        for(int i = 0; i < nums.size(); i++) {
            int x = abs(nums[i]);     

            int idx = x - 1;

            if(nums[idx] < 0) {
                an = x;
               continue;
            }

            nums[idx] = -nums[idx];  
        }

        int an2 = -1;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                an2 = i + 1;
                break;
            }
        }

        return {an, an2};
    }
};