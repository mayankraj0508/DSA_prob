class Solution {
public:
    int maxProfit(vector<int>& nums) {
          int buy = nums[0];
          int profit = INT_MIN;
          for(int i = 1; i<nums.size(); i++){
              profit = max(profit,nums[i]-buy);
              buy = min(buy,nums[i]);
          }
           if(profit==INT_MIN || profit <=0){
            return 0;
          }
          return profit ;
         
    }
};