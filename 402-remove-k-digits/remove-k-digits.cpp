class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
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

        int i = ans.size()-1;
        while(i>=0 && ans[i]=='0'){
            ans.pop_back();

            i--;
        }
       reverse(ans.begin(),ans.end());
        if(ans.size()==0) return "0";
        return ans;
    }
};