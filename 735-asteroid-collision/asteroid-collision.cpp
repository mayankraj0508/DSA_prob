class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        int n = nums.size();
        for(int i =0; i<n; i++){
            st.push(nums[i]);
            while(st.size() && st.top()<0 ){
                if(st.size()>=2){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    if(a*b<0){
                        if(a==-b){

                            break;
                        }
                        int mn = min(abs(a),abs(b));
                        if(abs(a)==mn){
                            st.push(b);
                        }
                        else{
                            st.push(a);
                        }

                    }
                    else{
                         st.push(b);
                         st.push(a);
                        break;
                    }

                }
                else{
                    break;
                }
            }
        }
        while(st.size()>1 && st.top()<0){
            int a  = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(a*b>0){
                st.push(b);
                st.push(a);
                break;
            }
            else{
                int mn = min(abs(a),abs(b));
                if(abs(a)==mn){
                    st.push(b);
                }
                else{
                    st.push(a);
                }
            }

        }
        vector<int>ans;
        while(st.size()){
              ans.push_back(st.top());
              st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;




      

        
    }
};