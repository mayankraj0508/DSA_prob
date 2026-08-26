class Solution {
public:
    vector<vector<int>>dp;
    long long  f(int i, int j,vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();
        if(i==m-1 && j==n-1) return dp[i][j] = grid[m-1][j];
        if(i>=m || i<0 || j>=n || j<0 ) return INT_MAX;
         if(dp[i][j]!=-1) return dp[i][j];
         
        return dp[i][j] = min(grid[i][j]+f(i+1,j,grid),grid[i][j]+f(i,j+1,grid));
    
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.resize(m,vector<int>(n,-1));
        return f(0,0,grid);

        
    }
};