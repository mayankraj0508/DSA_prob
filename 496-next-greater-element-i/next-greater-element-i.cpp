class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge(nums2.size());
        stack<int>st;
        int n = nums2.size();
        nge[n-1] = -1;
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(st.size() && nums2[i]>nums2[st.top()]){
                st.pop();
            }
            if(st.size()==0) nge[i] = -1;
            else nge[i] = st.top();
            st.push(i);;
        }
        unordered_map<int,int>m;
        for(int i = 0; i<nums2.size(); i++){
            m[nums2[i]] = nge[i];
        }
        vector<int>ans;
        for(int i = 0; i<nums1.size(); i++){
            if(m[nums1[i]]==-1) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(nums2[m[nums1[i]]]);
        }
        return ans ;
        
    }
};