class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
        int mx = -1;
        int n = nums.size();
        for(int i=n-1; i>=0 ; i--){
            int val = nums[i];
            nums[i] = mx;
            mx = max(mx,val);
            
        }
        return nums;
        
    }
};