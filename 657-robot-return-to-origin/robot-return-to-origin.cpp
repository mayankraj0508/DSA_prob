class Solution {
public:

   bool f(string &moves, int ll, int uu, int i){
       
       if(i==moves.size() && ll==0 && uu==0){
           return true;
       }
       if(i>=moves.size()){
        return false;
       }
       if(moves[i]=='U'){
          return f(moves,ll,uu+1,i+1);
       }
       else if(moves[i]=='D'){
           return f(moves,ll,uu-1,i+1);
       }
       else if(moves[i]=='L'){
          return f(moves,ll-1,uu,i+1);
       }
       else{
        return f(moves,ll+1,uu,i+1);
       }
       return false;
       
   }
    bool judgeCircle(string moves) {
        int i = 0;
        int j = 0;
        return f(moves,0,0,0);
        
    }
};