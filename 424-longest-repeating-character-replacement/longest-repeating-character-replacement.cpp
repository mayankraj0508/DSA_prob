class Solution {
public:
    int characterReplacement(string s, int k) {
        int i =0;
        int j =0;
        unordered_map<char,int>m;
        int mx_freq = 0;
        int ans = 0;
        while(i<s.size() && j<s.size()){
            m[s[j]]++;
            mx_freq = max(mx_freq,m[s[j]]);
            if((j-i+1)-mx_freq<=k){
               j++;
               ans = max(ans,j-i);
            }
            else{
                while(i<s.size() && (j-i+1)-mx_freq>k){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                    
                }
                j++;
             //   m[s[j]]++;

            }

        }
        ans = max(ans,j-i);
        return ans;
        
    }
};