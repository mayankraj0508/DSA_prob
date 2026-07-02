class Solution {
public:
   vector<vector<bool>>visited;
    int dp[51][51][102];
    bool check(vector<vector<int>>&grid, int i, int j, int health){
        if(health<1){
            return false;
        }
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return false;
        }
        health  = health-grid[i][j];
        if(dp[i][j][health]!=-1){
            return dp[i][j][health];
        }
        if(health>=1 && i==grid.size()-1 && j==grid[0].size()-1){
            return dp[i][j][health]=true;
        }
        if(visited[i][j]==true){
            return false;
        }
        visited[i][j] = true;
        
       bool ans  =  dp[i][j][health]= check(grid,i+1,j,health)|| check(grid,i,j+1,health) || check(grid,i-1,j,health) || check(grid,i,j-1,health);
       
        if(ans==true){
             visited[i][j] = false;
            return dp[i][j][health]=ans ;
        }
         visited[i][j] = false;
        return dp[i][j][health]=false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        memset(dp,-1,sizeof(dp));
        visited.resize(grid.size(),vector<bool>(grid[0].size(),false));
        return check(grid,0,0,health);
        
    }
};