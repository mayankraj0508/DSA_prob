class Solution {
public:
    #define pp pair<int,int>
    vector<vector<bool>>visited;
    void bfs(queue<pp>&q, vector<vector<int>>&mat){
        
        int time  = 0;
        while(q.size()){
            int sz = q.size();
            time++;
            for(int i = 0; i<sz; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                int dx[4] = {0,0,1,-1};
                int dy[4] = {-1,1,0,0};
                for(int k = 0; k<4; k++){
                    int nr = r+dx[k];
                    int nc = c+dy[k];
                    if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size()){
                        if(visited[nr][nc]==false){
                            q.push({nr,nc});
                            visited[nr][nc] = true;
                            if(mat[nr][nc]==1)
                            mat[nr][nc] = time;
                        }
                    }
                }
            }
         
        }



    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
         int n = mat[0].size();
         visited.resize(mat.size(),vector<bool>(mat[0].size(),false));
         queue<pp>q;
         for(int i = 0; i<m; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
         }
         bfs(q,mat);
         return mat;    
    }
};