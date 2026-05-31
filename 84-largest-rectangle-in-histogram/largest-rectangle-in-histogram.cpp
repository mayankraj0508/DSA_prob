class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int>nse(n);
         nse[n-1] = n;
         stack<int>st;
         st.push(n-1);
         for(int i =n-2; i>=0 ; i--){
            while(st.size() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
         }
         vector<int>pse(n);
         pse[0] = -1;
         stack<int>rt;
         rt.push(0);
         for(int i =1; i<n; i++){
            while(rt.size() && nums[rt.top()]>=nums[i]){
                rt.pop();
            }
            if(rt.size()==0){
                pse[i] = -1;
            }
            else{
                pse[i] = rt.top();
            }
            rt.push(i);
            
         }
         int ans = 0;
         for(int i =0; i<n; i++){
            int right = nse[i]-i-1;
            int left = i-pse[i]-1;
            ans  = max(ans, nums[i] + (left+right)*nums[i]);
         }
         return ans;
        
    }
};