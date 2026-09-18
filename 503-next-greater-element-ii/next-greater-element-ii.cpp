class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;
        int idx = -1;
        for(int i = 0; i<n-1; i++ ){
            if(nums[i]>nums[n-1]){
                nge[n-1] = i;
                idx = i;
                break;
            }
        }
        if(idx==-1) nge[n-1] = -1;
       
        for(int i = n-2; i>=0; i--){
            st.push(i);
        }
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(st.size() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(st.size()==0) nge[i] = -1;
            else 
            nge[i] =st.top();
            st.push(i);
        }
        vector<int>ans;
        for(int i = 0; i<nge.size(); i++){
            if(nge[i]==-1) {
                ans.push_back(-1);
                continue;
            }
           ans.push_back(nums[nge[i]]);
        }
        return ans ;
    }
};