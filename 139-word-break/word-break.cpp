class Solution {
public:
    unordered_map<string,bool>dp;
    bool f(string &s,string ant,int idx, vector<string>&word){
        if(dp.find(ant)!=dp.end()){
            return dp[ant];
        }
        if(ant.size()>s.size()){
            return dp[ant]=false;
        }
        if(s.substr(0,ant.size())!=ant){
            return dp[ant]= false;
        }
        if(ant==s){
            return dp[ant] = true;
        }
        for(int k = 0; k<word.size(); k++){
            bool ans = f(s,ant+word[k],idx+1,word);
            if(ans==true){
                return dp[ant]= true;
            }
        }
        return dp[ant] = false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {

     return f(s,"",0,wordDict);
        
    }
};