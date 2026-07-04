class Solution {
public:
   #define pp pair<int,int>
   vector<vector<bool>>visited;
    void f(int i, int j, vector<vector<char>>&board){
        visited[i][j] = true;
        board[i][j] = 'M';
         int dx[4] = {-1,1,0,0};
         int dy[4] = {0,0,1,-1};
         for(int k =0; k<4; k++){
            int nr = i+dx[k];
            int nc = j+dy[k];
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && visited[nr][nc]==false && board[nr][nc]=='O'){
                f(nr,nc,board);
            }
         }
         return ;
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
         visited.resize(m,vector<bool>(n,false));
         queue<pp>q;
         for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            }
             if(board[i][n-1]=='O'){
                q.push({i,n-1});
            }
         }
           for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                q.push({0,j});
            }
            if(board[m-1][j]=='O'){
                q.push({m-1,j});
            }
         }
         while(q.size()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(visited[i][j]==false){
                f(i,j,board);
            }
         }
         for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='M'){
                    board[i][j] = 'O';
                }
            }
         }

    }
};