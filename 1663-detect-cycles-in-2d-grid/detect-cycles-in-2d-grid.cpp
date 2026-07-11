class Solution {
public: 
    bool dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int i,int j,int pi,int pj){
      
        if(visited[i][j]==1){
            return true;
        }
        visited[i][j] = 1;
        int dx[4]= {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==grid[i][j]){
                if(pi==nx && pj==ny){
                    continue;
                }
                bool res = dfs(grid,visited,nx,ny,i,j);
                if(res){
                    return true;
                }

            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
               if(visited[i][j]==0){
                bool res = dfs(grid,visited,i,j,-1,-1);
                if(res){
                    return true;
                }
               }
            }
        }
        return false;
        
    }
};