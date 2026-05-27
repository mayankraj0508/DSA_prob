class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<int,int>m;
        for(int i =0; i<word.size(); i++){
            int ascii = word[i]-'0';
            if(m.find(ascii)!=m.end() && word[i]>='A' && word[i]<='Z'){
                 continue;
            }
            m[ascii]= i;
        }
        vector<int>alpha(26,0);
        for(int i =0; i<word.size(); i++){
            if(word[i]>='A' && word[i]<='Z'){
                continue;
            }
             int asc  = word[i]-'0';
             int x = asc-32;
             if(m.find(x)!=m.end() ){
                if(m[x]>i){
                  alpha[word[i]-'a']++;
                }
                else{
                    alpha[word[i]-'a'] = 0;
                }
                
             }
             else{
                alpha[word[i]-'a']--;
             }
        }
        int count = 0;
        for(int i =0; i<26; i++){
            if(alpha[i]>0){
                count++;
            }
        }
        return count;

        

        
    }
};