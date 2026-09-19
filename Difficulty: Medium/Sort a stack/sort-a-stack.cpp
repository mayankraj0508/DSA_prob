class Solution {
  public:
    void f(stack<int>&st, int val){
        if(st.size()==0){
            st.push(val);
            
        }
        else if(st.top()<val){
            st.push(val);
        }
        else{
            int x = st.top();
            st.pop();
            f(st,val);
            st.push(x);
        }
        
    }
    void sortStack(stack<int> &st) {
        if(st.size()==0) return ;
        // code here
        int x = st.top();
        st.pop();
        sortStack(st);
        f(st,x);
        
        
    }
};
