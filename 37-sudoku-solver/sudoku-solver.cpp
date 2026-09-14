class Solution {
public: 
    bool check(int i, int j, vector<vector<char>>&board, char ch){
        // checking row 
        for(int col  = 0; col<9; col++){
            if(board[i][col]==ch) return false;
        }
        for(int row = 0; row<9; row++){
            if(board[row][j]==ch) return false;
        }
        int sr  = i/3;
        int sc = j/3;
        int k = sc*3;
        int p =sr*3;
        for(int l = p; l<p+3; l++){
            for(int z = k; z<k+3; z++){
                if(board[l][z]==ch) return false;
            }
        }
        return true;

    }
    bool f(int i, int j,vector<vector<char>>& board){
        if(i==9) return true;
        if(j==9) return f(i+1,0,board);
        if(board[i][j]!='.') return f(i,j+1,board);

        for(char ch  = '1'; ch<='9'; ch++){
            if(check(i,j,board,ch)){
                board[i][j] = ch;
                bool x = f(i,j+1,board);
                if(x) return true;
                board[i][j] = '.';
            }
        }
        return false;


    }
    void solveSudoku(vector<vector<char>>& board) {
        bool z = f(0,0,board);
       


     



        
    }
};