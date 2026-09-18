class Solution {
public:
    bool isValid(string s) {
    stack<int>st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
        
            st.push(s[i]);
            continue;
        }
        else{
                if(st.size()==0) return false;
            if(s[i]==')'){
                while(st.size() && st.top()!='('){
                    if(st.top()=='{' ||st.top()=='[') return false;
                    st.pop();
                }
                    if(st.size())
                st.pop();
            }
            else  if(s[i]==']'){
                while(st.size() && st.top()!='['){
                    if(st.top()=='{' ||st.top()=='(') return false;
                    st.pop();
                }
                  if(st.size())
                  st.pop();
            }
              else{
                while(st.size() && st.top()!='{'){
                    if(st.top()=='(' ||st.top()=='[') return false;
                    st.pop();
                }
                      if(st.size())
                  st.pop();
            }
        }
    }
    return st.size()==0;

      
        
    }
};