class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //  for new dead vaklue is 3 and for new live the value is 2
        int m = board.size();
        int n = board[0].size();
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                int countlive = 0;
                int countdeath  = 0;
               int dx[8] = {-1,-1,-1,0,0,1,1,1};
               int dy[8] = {-1,0,1,-1,1,-1,0,1};
               for(int k = 0; k<8; k++){
                  int nr = i+dx[k];
                  int nc = j+dy[k];
                  if(nr>=0 && nr<m && nc>=0 && nc<n){
                      if(board[nr][nc]==1 || board[nr][nc]==3){
                          countlive++;
                      }
                      if(board[nr][nc]==0|| board[nr][nc]==2){
                          countdeath++;
                      }
                  }

               }
               if(board[i][j]==1){
                  if(countlive<2){
                     board[i][j] = 3;
                  }
                  else if(countlive>3){
                      board[i][j] = 3;
                  }
               }
               else{
                  if(countlive==3){
                      board[i][j]= 2;
                  }
               }
            }
        }
        for(int i =0; i<board.size(); i++){
              for(int j =0; j<board[0].size(); j++){
                  if(board[i][j]==2){
                      board[i][j] = 1;
                  }
                  else if(board[i][j]==3){
                      board[i][j] = 0;
                  }
              }
        }
        
        
    }
};