class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans  = "";
        int i = 0;
        int j = 0;
        int it = 0;
        while(i<word1.size() && j<word2.size()){
            if(it%2==0){
                ans  =  ans + word1[i];
                i++;
            }
            else{
                ans = ans +word2[j];
                j++;
            }
            it++;
        }
        if(i==word1.size()){
            ans  =  ans + word2.substr(j,word2.size()-j+1);
        }

         if(j==word2.size()){
            ans  =  ans + word1.substr(j,word1.size()-j+1);
        }
        return ans ;
        
        

        
    }
};