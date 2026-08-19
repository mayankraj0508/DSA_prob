class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
      unordered_map<string,vector<string>>m;
      for(int i = 0; i<s.size(); i++){
        string str = s[i];
        vector<int>freq(26,0);
        for(char c: str) freq[c-'a']++;
        string k = "";
        for(int p = 0; p<26; p++){
            k = k + to_string(freq[p])+'@';
        }
        m[k].push_back(str);
      }
      vector<vector<string>>ans;
      for(auto x: m){
          ans.push_back(x.second);
      }
      
      return ans ;
     
    }
};