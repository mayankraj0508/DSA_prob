class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int  i = 0; i<9; i++){
            vector<bool>visited(10,false);
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else if(visited[board[i][j]]==true){
                    return false;
                }
                else{
                    visited[board[i][j]] = true;
                }
            }
        }
        for(int j  = 0; j<9; j++){
            vector<bool>visited(10,false);
            for(int i =0; i<9; i++){
                if(board[i][j]=='.'){
                    continue;
                }
                else if(visited[board[i][j]]==true){
                    return false;
                }
                else{
                    visited[board[i][j]] = true;
                }
            }
        }
        int i = 0;
        int j = 0;
        while(i<9){
            vector<bool>visited(10,false);
            for(int k = i; k<i+3; k++){
                for(int l = j; l<j+3; l++){
                   if(board[k][l]=='.'){
                      continue;
                   }
                   else if(visited[board[k][l]]==true){
                      return false;
                   }
                   else{
                      visited[board[k][l]] = true;
                   }
                }
            }
            j = j+3;
            if(j==9){
                i = i+3;
                j = 0;
            }
        }
        return true;
    
    }
};