class Solution {
  public:
   #define pp pair<int,int>
    vector<vector<bool>>visited;
    int  bfs(int sr, int sc, int er, int ec, int n){
        queue<pp>q;
        q.push({sr,sc});
        visited[sr][sc] = true;
        int steps = 0;
        while(q.size()){
         int sz = q.size(); 
         for(int l =0; l<sz; l++){
         int i = q.front().first;
         int j =  q.front().second;
         q.pop();
         if(i==er && j==ec){
             return steps;
         }
         int dx[8] = {-2,-2,-1,-1,1,1,2,2};
         int dy[8] = {-1,1,-2,2,-2,2,-1,1};
         for(int k = 0; k<8; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr>=1 && nr<=n && nc>=1 && nc<=n && visited[nr][nc]==false){
                visited[nr][nc] = true;
                q.push({nr,nc});
                
            }
        }
        }
        steps ++ ;
            
        }
        return -1;
        
    }
    int  f(int sr, int sc, int er, int ec, int n){
        if(sr>n || sr<1 || sc>n || sc<1){
            return INT_MAX;
        }
        if(sr==er && sc==ec){
            return 0;
        }
        int dx[8] = {-2,-2,-1,-1,1,1,2,2};
        int dy[8] = {-1,1,-2,2,-2,2,-1,1};
        long long  ans  = INT_MAX;
        visited[sr][sc] = true;
        for(int k = 0; k<8; k++){
            int nr = sr + dx[k];
            int nc = sc + dy[k];
            if(nr>0 && nr<=n && nc>0 && nc<=n && visited[nr][nc]==false){
                ans  =  min(ans, 1+ (long long)f(nr,nc,er,ec,n));
            }
        }
        visited[sr][sc] = false;
        return ans ;
        
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
    visited.resize(n+1,vector<bool>(n+1,false));
    int sr = knightPos[0];
    int sc = knightPos[1];
    int er = targetPos[0];
    int ec = targetPos[1];
    return  bfs(sr,sc,er,ec,n);
    
        
    }
};