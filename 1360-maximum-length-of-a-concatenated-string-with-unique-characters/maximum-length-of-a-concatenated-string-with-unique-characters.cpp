class Solution {
public:
    void f(int i, vector<string>&arr, string ans,int &mx){
        vector<int>freq(27,0);
        bool flag = false;
         for(int i = 0; i<ans.size(); i++){
            if(freq[ans[i]-'a']>0){
                flag = true;
                break;
            }
            else{
                freq[ans[i]-'a']++;
            }
         }
        if(flag==false){
           if(ans.size()>mx){
              mx = ans.size();
           }
        }
        if(i==arr.size()){
            return ;
        }
     
     
        f(i+1,arr,ans+arr[i],mx);
     
        f(i+1,arr,ans,mx);
    }
    int maxLength(vector<string>& arr) {
        int mx = 0;
        string ans = "";
        f(0,arr,ans,mx);
        return mx;

        
    }
};