class Solution {
  public:
    #define pp pair<int,int>
    vector<vector<bool>>visited;
    void bfs(vector<vector<int>>&grid,queue<pp>&q){
        while(q.size()){
            int sz = q.size();
            for(int k =0; k<sz; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                //right
                if(j<grid[0].size()-1 && visited[i][j+1]==false){
                    int dist = 1+ grid[i][j];
                    grid[i][j+1] = dist;
                    visited[i][j+1]=true;
                    q.push({i,j+1});
                }
            //down
                if(i<grid.size()-1 && visited[i+1][j]==false){
                    int dist = 1+grid[i][j];
                    grid[i+1][j] = dist;
                    visited[i+1][j]=true;
                     q.push({i+1,j});
                }
                //left
                 if(j>=1 && visited[i][j-1]==false){
                    int dist = 1+grid[i][j];
                    grid[i][j-1] = dist;
                    visited[i][j-1]=true;
                     q.push({i,j-1});
                }
                //up
                if(i>=1 && visited[i-1][j]==false){
                    int dist  = 1+grid[i][j];
                    grid[i-1][j] = dist;
                    visited[i-1][j]=true;
                     q.push({i-1,j});
                }
            }
        }
    
    }
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pp>q;
        visited.resize(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j =0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j]= 0;
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        bfs(grid,q);
        return grid;
  
    }
};