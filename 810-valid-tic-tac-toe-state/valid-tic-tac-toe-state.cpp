class Solution {
public:
    bool check(vector<string>&board,char ch){
        for(int i=0; i<3; i++){
            if(board[i][0]==ch && board[i][1]==ch && board[i][2]==ch){
                return true;
            }
        }
         for(int j=0; j<3; j++){
            if(board[0][j]==ch && board[1][j]==ch && board[2][j]==ch){
                return true;
            }
        }
        if(board[0][0]==ch && board[1][1]==ch && board[2][2]==ch){
            return true;
        }
        if(board[0][2]==ch && board[1][1]==ch && board[2][0]==ch){
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
                int cntx = 0;
        int cnto = 0;
        for(int i =0; i<board.size(); i++){
            for(int j =0; j<3; j++){
                if(board[i][j]=='X'){
                    cntx++;
                }
                if(board[i][j]=='O'){
                    cnto++;
                }
            }
        }
       if(cntx!=cnto){
          if(cntx!=cnto+1){
            return false;
          }
       }
        bool xwin = check(board,'X');
        bool owin = check(board,'O');
        if(xwin && owin){
            return false;
        }
        if(xwin){
            if(cntx!=cnto+1){
                return false;
            }
        }
        if(owin){
            if(cntx!=cnto){
                return false;
            }
        }
        return  true;

        
    }
};