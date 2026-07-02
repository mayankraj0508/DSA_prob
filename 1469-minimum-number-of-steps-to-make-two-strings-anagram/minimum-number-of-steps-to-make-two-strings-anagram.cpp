class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(int i =0; i<s.size(); i++){
            m[s[i]]++;
        }
        unordered_map<char,int>m2;
        for(int i = 0; i<t.size(); i++){
            m2[t[i]]++;
        }
        int sum  = 0;
        for(auto x:m2){
           if(x.second>m[x.first]){
              sum  = sum + x.second-m[x.first];
           }
        }
        return sum;
        
    }
};