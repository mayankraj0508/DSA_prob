class Solution {
public:
    vector<int>dp;
    int f(int n){
        if(n==0)  return dp[n]=1;
        if(n<0) return 0;
        if(dp[n]!=-1)  return dp[n];
        

        return dp[n] = f(n-1)+f(n-2);
    }
    int f(int i ,int n){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
       
        int ans1 = f(i+1,n);
        int ans2 = f(i+2,n);
        return dp[i] =ans1+ans2;
    }
    int climbStairs(int n) {
     dp.resize(50,-1);
     return f(n);
        
    }
};