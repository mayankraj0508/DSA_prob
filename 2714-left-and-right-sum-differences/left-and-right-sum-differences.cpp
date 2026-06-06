class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n  = nums.size();
        vector<int>suf(n);
        suf[n-1]  = 0;
        for(int i=n-2; i>=0 ; i--){
            suf[i] = suf[i+1] + nums[i+1];
        }
        int sum  = 0;
        for(int i =0; i<n; i++){
            int x = nums[i];
             nums[i] = abs(sum-suf[i]);
             sum = sum + x;
        } 
        return nums;
        
    }
};