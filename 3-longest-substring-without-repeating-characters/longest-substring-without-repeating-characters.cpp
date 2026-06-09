class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1 || s.size()==0){
            return s.size();
        }
        vector<int>freq(256,0);
        int i =0; 
        int j =1;
        freq[s[i]]++;
        int mx_size = 0;
        while(i<s.size() && j<s.size()){
            if(freq[s[j]]==0){
                freq[s[j]]++;
                j++;
                
                
            }
            else{
                mx_size = max(mx_size,j-i);
                while(i<s.size() && s[i]!=s[j]){
                    freq[s[i]]--;
                    i++;
                }
                freq[s[i]]--;
                i++;
                freq[s[j]]++;
                j++;
            }

        }
        mx_size = max(mx_size,j-i);
        return mx_size;


        
    }
};