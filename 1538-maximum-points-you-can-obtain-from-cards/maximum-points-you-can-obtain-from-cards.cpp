class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int left = 0;;
        int right = 0;
        for(int i =0; i<k; i++){
            left = left + nums[i];
        }
        int n = nums.size();
        int ans = 0;
        ans = max(ans,left+right);;
        for(int i = 0; i<k; i++){
          //ans = max(ans,left+right);
           left = left-nums[k-1-i];
           right = right + nums[n-1-i];
            
           ans = max(ans,left+right);
        }
        return ans;

        
    }
};