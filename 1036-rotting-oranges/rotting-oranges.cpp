class Solution {
public:
#define pp pair<int,int>
   void bfs(vector<vector<int>>&grid,vector<vector<int>>&visited,queue<pp>&q,int &time){
        while(q.size()){
            int sz = q.size();
            time++;
            for(int i =0; i<sz; i++){
            int row = q.front().first;
            int col  = q.front().second;
            q.pop();
        //    time++;
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};
            for(int k = 0; k<4; k++){
                int nr = row+dx[k];
                int nc = col+dy[k];
                
                if(nr>=0&&nr<grid.size()&& nc>=0&&nc<grid[0].size()&&visited[nr][nc]==0&&grid[nr][nc] ==1){
                    visited[nr][nc] = 1;
                    grid[nr][nc] =2;
                    q.push({nr,nc});
                }
            }
            }
        

        }
   }
    int orangesRotting(vector<vector<int>>& grid) {
        int row  = -1;
        int col  = -1;
        queue<pp>q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i =0;i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                q.push({i,j});
                visited[i][j] = 1;
                }
            }
        }
        int time  = -1;
        bfs(grid,visited,q,time);
        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(time==-1){
            return 0;
        }
        return time;


        
    }
};