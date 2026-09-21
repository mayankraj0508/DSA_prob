class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        for(int i = 0; i<nums.size(); i++){
            int x = abs(nums[i]);
            bool flag  = true;
            if(nums[i]<0){
                while(st.size() && st.top()>0){
                    int v = st.top();
                    st.pop();
                    if(x==v){
                        flag  = false;
                      break;
                    }
                    else if(x>v){
                        
                       continue;

                    }
                    else{
                        st.push(v);
                        flag  = false;
                        break;
                    }
                    
                }
            }
            if(flag){
            
            st.push(nums[i]);
        }
        }
        vector<int>ans;
        while(st.size()){
            int x = st.top();
            st.pop();
            ans.push_back(x);

        }
        reverse(ans.begin(),ans.end());
        return ans ;

    }
};