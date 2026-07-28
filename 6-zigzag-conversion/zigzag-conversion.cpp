class Solution {
public:
    string convert(string s, int numRows) {
        int n  = s.size();
         if(numRows==1){
            return s;
         }
        int ele =2*(numRows-1);
        int cycle = n/ele;
        int rem   = n%ele;
    
     
        int col  = (numRows-1)*cycle;
           if(rem!=0){
            if(rem<=numRows){
                col++;

            }
            else{
                col+=2;
            }
        }
      
        // cout<<col;
        vector<vector<char>>v(numRows,vector<char>(s.size(),'*'));
        int i   = 0;
        int j = 0;
        int  k = 0;
        col = s.size();
        while(i<numRows && j<col && k<s.size() && k>=0){
            if(i==0){
                while(i<numRows && k<s.size()){
                    v[i][j] = s[k];
                    k++;
                   i++; 
                }
            }
           
            
                i = numRows-2;
                j++;
                while(i>0 && j<col && k<s.size()){
                  
                    
                    v[i][j] = s[k];
                    i--;
                    j++;
                    k++;
                 

                }
                i = 0;
         
                
            
        }
      string ans  = "";
    
      for(int i = 0; i<numRows; i++){
         for(int j = 0; j<col; j++){
            if(v[i][j]!='*'){
                ans  =  ans + v[i][j];
            }
         }
      }
      return ans ;

        
    }
};