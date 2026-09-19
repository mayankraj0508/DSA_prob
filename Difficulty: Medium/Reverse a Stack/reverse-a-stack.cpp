class Solution {
  public:
    void f(stack<int>&st, int val){
        if(st.size()==0) {
            st.push(val);
            return ;
        }
        else{
             int v = st.top();
             st.pop();
             f(st,val);
             st.push(v);
        }
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.size()==0) return ;
        int x = st.top();
        st.pop();
        reverseStack(st);
        f(st,x);
        
        
    }
};