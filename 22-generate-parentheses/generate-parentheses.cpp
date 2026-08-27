class Solution {
public:
   vector<string>finls;
    void f(string ans , int n,int open, int close){
        if(close>open) return ;
         if(open>n) return ;
        
        if(open==close){
            if(open==n){
                finls.push_back(ans);
                return ;
            }
            ans.push_back('(');
            f(ans,n,open+1,close);
        }
        else{
            ans.push_back('(');
            f(ans,n,open+1,close);
            if(ans.size()) ans.pop_back();
            ans.push_back(')');
            f(ans,n,open,close+1);
        }

        
    }
    vector<string> generateParenthesis(int n) {
        string ans  = "";
        
        f(ans,n,0,0);
        return finls;
         
        
        
    }
};