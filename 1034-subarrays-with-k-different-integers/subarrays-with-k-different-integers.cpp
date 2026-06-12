class Solution {
public:
    int f(vector<int>&s, int k){
        int i =0;
        int j = 0;
        int ans = 0;
        unordered_map<int,int>m;
        while(j<s.size()){
            m[s[j]]++;  
               while(m.size()>k && i<s.size()){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]);
                }
                i++;
            }
            if(m.size()<=k){
                ans = ans+j-i+1;
            }
            j++;
         
        }
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& s, int k) {
        return f(s,k)-f(s,k-1);
         
    }
};