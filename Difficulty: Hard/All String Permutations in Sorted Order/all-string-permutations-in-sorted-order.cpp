class Solution {
  public:
    vector<string>ans;
    void f(string &s, int idx){
        if(idx==s.size()){
            ans.push_back(s);
            return ;
        }
        for(int i = idx; i<s.size();  i++){
            swap(s[i],s[idx]);
            f(s,idx+1);
            swap(s[i],s[idx]);
        }
    }
    vector<string> permutation(string s) {
     
        f(s,0);
         sort(ans.begin(),ans.end());
        return ans ;
        
        
    }
};