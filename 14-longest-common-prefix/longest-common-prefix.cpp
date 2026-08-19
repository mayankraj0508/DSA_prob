class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string a = strs[0];
        string p = strs[strs.size()-1];
        
        int i = 0; 
        string ans = "";
        int lt = min(a.size(),p.size());
       while(i<lt && a[i]==p[i]){
          ans = ans+a[i];
          i++;
       }
        return ans;

    }
};