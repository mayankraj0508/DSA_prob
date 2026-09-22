class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
       int top = 0;
       int down  = mat.size()-1;
       while(top<down){
           if(mat[top][down]==1 && mat[down][top]==1){
               top++;
               down--;
               
           }
           else if(mat[top][down]==1 && mat[down][top]==0){
               top++;
           }
           else{
               down--;
           }
       }
       for(int  j =0; j<mat.size(); j++){
           if(mat[top][j]==1 && top!=j) return -1;
           else if(mat[j][top]==0) return -1;
       }
       return top;
       
    }
};