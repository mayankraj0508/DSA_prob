class Solution {
public:
    #define pp pair<int,int>
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   int n = nums.size();
        vector<int>nge(n);
        nge[n-1] = -1;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2; i>=0 ; i--){
            while(st.size() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                nge[i] = -1;
            }
            else{
                nge[i]  = st.top();
                
            }
            st.push(i);
        }
        vector<int>ans;
        for(int i = 0; i<nums.size()-k+1; i++){
            int x = i;
            while(nge[x]<i+k && nge[x]!=-1 ){
                x = nge[x];

            }
            if(x!=-1){
                ans.push_back(nums[x]);
            }
            else{
                ans.push_back(nums[i]);
            }
            
        }
        return ans ;
        
    }
};