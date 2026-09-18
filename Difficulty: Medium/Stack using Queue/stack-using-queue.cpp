class myStack {
    queue<int> q;

  public:

    void push(int x) {
        // Inserts an element x at the top of the stack
        q.push(x);
        
    }

    void pop() {
        // Removes an element from the top of the stack
        if(q.size()==0) return ;
         int sz = q.size();;
         for(int i = 0; i<sz-1; i++){
             int x = q.front();
             q.pop();
             q.push(x);
             
         }
         if(q.size())
         q.pop();
         
    }

    int top() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(q.size()==0) return -1;
        int sz = q.size();;
        for(int i = 0; i<sz-1; i++){
            int x = q.front();
            q.pop();
            q.push(x);
        }
        int v = q.front();
        q.pop();
        q.push(v);
        return v;
    }

    int size() {
        // Returns the current size of the stack
        return q.size();
    }
};
