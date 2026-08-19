class Solution {
public:
    int m;
    int n;
    void dfs(vector<vector<char>>&grid, int i, int j,vector<vector<bool>>&visited){
        if(i<0 || j<0 || i>=m || j>=n ){
            return ;
        }
        if(visited[i][j]==true) return ;
        visited[i][j] = true;
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k = 0; k<4; k++){
            int nr  = i+dx[k];
            int nc = j + dy[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1' &&  visited[nr][nc]==false){
                dfs(grid,nr,nc,visited);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        this->m  = grid.size();
        this->n =  grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count  = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    count++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return count;

        
    }
};