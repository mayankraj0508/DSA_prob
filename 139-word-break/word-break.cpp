class Solution {
public:
    
     vector<int>dp;
     bool f(string &s, vector<string>&word,int sz){
        if(sz>s.size())  return false;
        if(sz==s.size()){
          return dp[sz] = true;     
        }
  
       if(dp[sz]!=-1) {
          if(dp[sz]==1 )return true;
          return false;
       }
        for(int i = 0; i<word.size(); i++){
            string p = word[i];
            if(sz+p.size()<=s.size() && s.substr(sz,p.size())==p){
                bool x = f(s,word,sz+p.size());
                if(x) return dp[sz] =  true;

            }

        }
        return  dp[sz]  = false;


     }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        dp.resize(s.size()+5,-1);
        return f(s,wordDict,0);
        
    }
};