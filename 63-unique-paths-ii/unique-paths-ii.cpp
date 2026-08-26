class Solution {
public:
    
    int f(int i, int j, vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || i<0 || j>=n || j<0) return 0;
        if(grid[i][j]==1) return 0;
        return f(i,j+1,grid)+f(i+1,j,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        // return f(0,0,grid);
        // tabulation 
         int m = grid.size();
    
        int n = grid[0].size();
        if(grid[m-1][n-1]==1) return 0;
        vector<vector<long long>>dp(m,vector<long long>(n,0));
       dp[m-1][n-1] = 1;
       for(int i = m-1; i>=0 ; i--){
        for(int j = n-1; j>=0; j--){
            if(grid[i][j]==1) continue;
            if(i==m-1 && j==n-1) continue;
            if(i+1<m){
                dp[i][j] = dp[i+1][j]+dp[i][j];
            }
            if(j+1<n){
                dp[i][j] = dp[i][j] + dp[i][j+1];
            }
           
          

        }
       }
       return dp[0][0];

        
    }
};