class Solution {
public:
    int compress(vector<char>& chars) {
        string  ans  = "";
        int i =1;
        ans = ans + chars[0];
        while(i<chars.size()){
            int count  =1;
            int k = i;
            if(chars[i]==chars[i-1]){
                while(i<chars.size() && i>=1 && chars[i]==chars[i-1]){
                    count++;
                    i++;
                }
            }
            if(count==1  ){
                if(k==1){
                ans.push_back(chars[k]);
                i++;
                }
                else{
                ans.push_back(chars[i]);
                i++;
                }

            }
            else{
                if(k==1){
                    string p = to_string(count);
                    ans = ans + p; 
                }
                else{
                    if(ans[ans.size()-1]!=chars[i-1])
                    ans  =  ans + chars[i-1];
                     string p = to_string(count);
                     ans  =  ans + p;
                }
            }
           
        }
        chars.clear();
        
        for(int  i=0; i<ans.size(); i++){
            chars.push_back(ans[i]); 
        }
        return chars.size();
       
    }
};