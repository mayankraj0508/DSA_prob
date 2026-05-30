class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
              // code here
        
        // first find sum of subarray maximums 
        //for this we have to find NGE nad PGE element and then continue
        int n = nums.size();
        vector<int>nge(n);
        nge[n-1] = -1;
        stack<int>st;
        st.push(n-1);
        for(int i =n-2; i>=0 ; i--){
            while(st.size() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                nge[i] =-1;
            }
            else{
                nge[i] =st.top();
            }
            st.push(i);
        }
        vector<int>pge(n);
        stack<int>rt;
        pge[0] = -1;
        rt.push(0);
        for(int i =1; i<n; i++){
            while(rt.size()>0 && nums[rt.top()]<nums[i]){
                rt.pop();
            }
            if(rt.size()==0){
                pge[i] = -1;
            }
            else{
                pge[i] = rt.top();
            }
            rt.push(i);
        }
        //find the sum of subarray maximums 
        long long  sum = 0;
        for(int i =0; i<nums.size(); i++){
            int right  = nge[i]-i;
            if(nge[i]==-1){
                right = n-i;
            }
            int left = i-pge[i];
            if(pge[i]==-1){
                left = i+1;
            }
            sum = sum + (long long)nums[i]*left*right;
            
        }
        //finding the subarray mminmims 
        // to finf this we need to find the NSE nd PSE
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>nt;
        stack<int>pt;
        nse[n-1] = -1;
        nt.push(n-1);
        for(int i = n-2; i>=0 ; i--){
            while(nt.size() && nums[nt.top()]>=nums[i]){
                nt.pop();
            }
            if(nt.size()==0){
                nse[i] = -1;
            }
            else{
                nse[i] = nt.top();
            }
            nt.push(i);
        }
        pse[0] = -1;
        pt.push(0);
        for(int i =1; i<n; i++){
            while(pt.size() && nums[pt.top()]>nums[i]){
                pt.pop();
            }
            if(pt.size()==0){
                pse[i] = -1;
            }
            else{
                pse[i] = pt.top();
            }
            pt.push(i);
        }
        //find sum pof subarray minnimium 
        long long  sum2= 0;
        for(int i =0; i<nums.size(); i++){
            int right  = nse[i]-i;
            if(nse[i]==-1){
                right = n-i;
            }
            int left = i-pse[i];
            if(pse[i]==-1){
                left = i+1;
            }
            sum2= sum2 + (long long)nums[i]*left*right;
        }
        return sum-sum2;
          
    }
};