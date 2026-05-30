class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
        // if(k==1 && nums.size()==1){
        //     return "0";
        // }
        for(int i =0; i<nums.size(); i++){
            while(st.size()>0 && st.top()>nums[i] && k){
                st.pop();
                k--;

            }
            st.push(nums[i]);

        }
           while (st.size() && k > 0) {
            st.pop();
            k--;
        }
       string ans = "";
       while(st.size()){
          ans.push_back(st.top());
          st.pop();
       }
       reverse(ans.begin(),ans.end());
        int i =0; 
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
       
        string t  = ans.substr(i);
       
        if(t==""){
            return "0";
        }
        return t;

        
    }
};