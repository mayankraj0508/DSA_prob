class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i = n-2; i>=0; i--){
            st.push(i);
        }
        for(int i = n-1; i>=0; i--){
            while(st.size() && nums[i]>=nums[st.top()]){
                st.pop();
            }
            if(st.size()) nge[i] = st.top();
            else nge[i] = -1;
            st.push(i);
        }
        vector<int>ans;
        for(int i = 0;i<nums.size(); i++){
            if(nge[i]==-1){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(nums[nge[i]]);
        }
        return ans ;
        
    }
};