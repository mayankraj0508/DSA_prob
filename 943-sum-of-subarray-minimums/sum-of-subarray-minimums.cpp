class Solution {
public:
    long long  mod =   1e9 +7;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int>nse(n);
        vector<int>pse(n);
        nse[n-1] = -1;
        stack<int>st;
        st.push(n-1);
        for(int i =n-2; i>=0 ; i--){
            while(st.size()>0 && nums[st.top()]>nums[i]){
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
        pse[0] = -1;
        stack<int>rt;
        rt.push(0);
        for(int i=1; i<n; i++){
            while(rt.size() && nums[rt.top()]>=nums[i] ){
                rt.pop();
            }
            if(!rt.size()){
                pse[i] = -1;
            }
            else{
                pse[i] = rt.top();
            }
            rt.push(i);
        }
        long long  ans = 0;
        for(int i =0; i<n; i++){
            int right = nse[i]-i;
            if(nse[i]==-1){
                right = n-i;
            }
            int left = i-pse[i];
            if(pse[i]==-1){
                left = i+1;
            }
            long long f = (nums[i]*(long long)left*right)%mod;
            ans = (ans + f)%mod;

        }
        return ans%mod;
        
    }
};