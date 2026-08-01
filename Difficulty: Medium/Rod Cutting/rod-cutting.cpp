class Solution {
  public:
    vector<int>dp;
    int f(vector<int>&prices, int sum){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return INT_MIN;
        }
        if(dp[sum]!=-1){
            return dp[sum];
        }
        int ans  = 0;
        for(int i = 1; i<=prices.size(); i++){
           dp[sum] =  ans  = max(ans ,prices[i-1]+f(prices,sum-i));
        }
        return dp[sum] = ans ;
    }
    int cutRod(vector<int> &price) {
        // code here
        dp.resize(1005,-1);
        return f(price,price.size());
        
        
    }
};