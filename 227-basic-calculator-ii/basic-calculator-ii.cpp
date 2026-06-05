class Solution {
public:
     bool isoperator(char ch){
         if(ch=='+' || ch=='-'||ch=='*'||ch=='/' ||ch==' '){
            return true;
         }
         return false;
     }
    int pr(char ch){
        if(ch=='+' || ch=='-'){
            return 1;
        }
       return 2;
    }
    int solve(int a, char ch, int b){
        if(ch=='+'){
            return a+b;
        }
        else if(ch=='-'){
            return a-b;
        }
        else if(ch=='*'){
            return a*b;
        }
        else{
            return a/b;
        }
    }
    int calculate(string s) {
        stack<int>st;
        stack<char>op;
        int i =0;
        while( i<s.size()){
            if(!isoperator(s[i])){
                string t = "";
               
                while(i<s.size() && !isoperator(s[i])){
                    t = t+s[i];
                    i++;
                }
                st.push(stoi(t));
            }
            else{
                if(s[i]==' '){
                    i++;
                }
                else if(op.size()==0 || pr(op.top())<pr(s[i])){
                    op.push(s[i]);
                    i++;
                }
                else{
                    while(op.size() && pr(op.top())>=pr(s[i])){
                        int val2 = st.top();
                        st.pop();
                        int val1 = st.top();
                        st.pop();
                        char ch = op.top();
                        op.pop();
                        int result = solve(val1,ch,val2);
                        
                        st.push(result);
                    }
                    op.push(s[i]);
                    i++;
                }
            }

        }
        while(op.size()){
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
            char ch = op.top();
            op.pop();
            int result = solve(val1,ch,val2);
           
            st.push(result);
        }
        if(st.size()){
            return st.top();
        }
        return -1;
    }
};