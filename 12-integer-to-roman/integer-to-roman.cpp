class Solution {
public:
  
    string f(char ch , int tens){
        int num  = ch-'0';
        string ans  = "";
        if(tens==3){
            for(int i =0; i<num; i++){
                ans  =  ans +'M';
            }
            return ans;
        }
        else if(tens==2){
            if(num<4){
                for(int i =0; i<num; i++){
                ans  =  ans +'C';
            }
            return ans;
        }
        else if(num==4){
            return  "CD";
        }
        else if(num==9){
            return "CM";
        }
        else{
            num = num-5;
            ans = ans + "D";
            for(int i = 0; i<num ; i++){
                ans  =  ans + "C";
            }
            return ans;
        }

        }
        else if(tens==1){
        if(num<4){
             for(int i =0; i<num; i++){
                ans  =  ans +'X';
            }
            return ans;
                return ans ;
        }
        else if(num==4){
            return  "XL";
        }
        else if(num==9){
            return "XC";
        }
        else{
            ans  = ans + 'L';
            num  = num-5;
             for(int i =0; i<num; i++){
                ans  =  ans +'X';
            }
            return ans;
            
        }

            

        }
        else{
            if(num<4){
                for(int i = 0; i<num; i++){
                    ans  =  ans + 'I';
                }
                return ans ;
        }
        else if(num==4){
            return "IV";
        }
        else if(num==9){
            return "IX";
        }
        else{
            num  = num-5;
            ans  =  ans + 'V';
            for(int i = 0; i<num; i++){
                ans  =  ans + 'I';
            }
            return ans ;
        }
        }
        return "";
    



        
    }
    string intToRoman(int num) {
        string ans  = "";
        string temp = to_string(num);
        int sz = temp.size();
    
        for(int i  = 0; i<temp.size(); i++){
            ans  =  ans + f(temp[i],sz-i-1);
        }
        return ans ;
    }
};