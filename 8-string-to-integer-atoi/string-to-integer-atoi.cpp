class Solution {
public:
    char sign = '#';

    void f(string &s, int i, string &ans){

        if(i>=s.size()){
            return ;
        }

        while(i<s.size()-1 && s[i]=='0' && s[i]==s[i+1] && ans.size()==0){
            i++;
        }
        if(s[i]==' ' && sign!='#'){
            return ;
        }
       else  if((s[i]==' ' ) && ans.size()==0 ){
            f(s,i+1,ans);
        }

        else if(sign!='#' && (s[i]=='+' || s[i]=='-')){
            return ;
        }

        else if((s[i]=='-' || s[i]=='+' )&& ans.size()==0){
            sign = s[i];
            f(s,i+1,ans);
        }

        else if((ans.size()==0) && !(s[i]>='0' && s[i]<='9')){
            return ;
        }

        else if(ans.size()!=0 && !(s[i]>='0' && s[i]<='9')){
            return ;
        }

        else{
            ans = ans+s[i];
            f(s,i+1,ans);
        }
    }

    int myAtoi(string s) {

        string ans = "";

        f(s,0,ans);

        if(ans.size()==0){
            return 0;
        }

        // positive overflow
        if(sign=='#' || sign=='+'){

            if(ans.size()>10){
                return INT_MAX;
            }

            if(ans.size()==10 && ans>"2147483647"){
                return INT_MAX;
            }
        }

        // negative overflow
        if(sign=='-'){

            if(ans.size()>10){
                return INT_MIN;
            }

            if(ans.size()==10 && ans>"2147483648"){
                return INT_MIN;
            }
        }

        long long val = stoll(ans);

        if(sign=='-'){
            return -val;
        }

        return val;
    }
};