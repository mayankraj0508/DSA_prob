class Solution {
public:
    vector<vector<string>>ans;
    bool check(string s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f(vector<string>temp,int idx, string s ){
        if(idx==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i = idx; i<s.size();  i++){
            if(check(s,idx,i)){
                string x = s.substr(idx,i-idx+1);
                temp.push_back(x);
                f(temp,i+1,s);
                temp.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        f(temp,0,s);
        return ans;
       
    }
};