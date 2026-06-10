class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0; 
        int j = 0;
        int  cnta = 0;
        int cntb = 0;
        int cntc = 0;
        int ans = 0;
        while(i<s.size() && j<s.size()){
            if(s[j]=='a'){
                cnta++;
            }
             if(s[j]=='b'){
                cntb++;
            }
            if(s[j]=='c'){
                cntc++;;
            }

           
                while(i<s.size() && cnta!=0 && cntb!=0 && cntc!=0){
                     ans = ans+s.size()-j;
                     if(s[i]=='a'){
                        cnta--;
                     }
                     else if(s[i]=='b'){
                        cntb--;
                     }
                     else{
                        cntc--;
                     }
                     i++;
                }
            
            
               j++;
            
        }
        return ans;


        
        
    }
};