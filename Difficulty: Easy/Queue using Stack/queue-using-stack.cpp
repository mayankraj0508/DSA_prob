class myQueue {

  public:
    stack<int>st;
    void f(stack<int>&st, int val){
        if(st.size()==0) {
            st.push(val);
            return;
        }
        int x =  st.top();
        st.pop();
        f(st,val);
        st.push(x);
        
    }
    myQueue() {
        // Initialize your data members
        
    }

    void enqueue(int x) {
        // Implement enqueue operation
        f(st,x);
    }

    void dequeue() {
        // Implement dequeue operation
        if(st.size()==0) return ;
        st.pop();
    }

    int front() {
        if(st.size()==0) return -1;
        // Implement front operation
        return st.top();
    }

    int size() {
        // Implement size operation
         return st.size();
    }
};
