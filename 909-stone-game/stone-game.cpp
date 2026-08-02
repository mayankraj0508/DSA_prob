class Solution {
public:
    int dp[501][501][2];
    int f(vector<int>&piles, int start , int end, bool alice){
        if(start>end){
            return 0;
        }
        if(alice){
        if(dp[start][end][1]!=-1){
            return dp[start][end][1];
        }
        }
        if(!alice){
            if(dp[start][end][0]!=-1){
            return dp[start][end][0];
        }
        }
        if(alice){
           return  dp[start][end][1] =max(piles[start]+f(piles,start+1,end,!alice),piles[end]+f(piles,start,end-1,!alice));
        }
        else{
          return dp[start][end][0] =   min(f(piles,start+1,end,!alice),f(piles,start,end-1,!alice));
        }
        
    }
    bool stoneGame(vector<int>& piles) {
        int  n = piles.size();
        int total  =  0;
        for(int i = 0; i<piles.size(); i++){
            total  += piles[i];
        }
        // cout<<f(piles,0,n-1,true);
        memset(dp,-1,sizeof(dp));
        if(f(piles,0,n-1,true)>n/2){
            return true;
        }
        return false;
        
    }
};