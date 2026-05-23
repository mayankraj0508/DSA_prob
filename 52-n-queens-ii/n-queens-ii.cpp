class Solution {
public:
    bool check(int i, int j,vector<vector<char>>&chess){
        int n = chess.size();
         for(int row = 0; row<=i-1; row++){
             for(int col = 0;col<n; col++){
               
                if(abs(row-i)==abs(col-j) && chess[row][col]=='q'){
                    return false;
                }
                if(col==j && chess[row][col]=='q'){
                    return false;
                }
             }
         }
         return true;
    }
    int f(vector<vector<char>>&chess, int i){
        int n = chess.size();
        if(i==n){
            
            return 1;
            
        }
        int ans = 0;
        for(int k = 0; k<n; k++){
            if(check(i,k,chess)){
              chess[i][k] = 'q';
              ans  = ans+f(chess,i+1);
              chess[i][k]='#';
            }
        }
        
        return ans;

    }
    int totalNQueens(int n) {
      vector<vector<char>>chess(n,vector<char>(n,'#'));
      int i =0;
      return f(chess,i);
     

        
    }
};